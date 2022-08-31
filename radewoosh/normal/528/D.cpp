#include <bits/stdc++.h>
using namespace std;

double PI=3.141592653589793;

complex <double> dftn[530007];
complex <double> dfts[530007];
complex <double> pom[530007];

inline int potenga(int v)
{
    for (int i=1; 1; i<<=1)
    {
        if (i>=v)
        {
            return i;
        }
    }
}

inline void dft(int n, complex <double> omega)
{
    vector < complex <double> > wek;

    wek.push_back(omega);
    for (int i=2; i<n; i<<=1)
    wek.push_back(wek.back()*wek.back());

    complex <double> jeden;
    int n2=n-1;
    int s=0;
    int p;

    for (int i=2; i<=n; i<<=1)
    {
        omega=wek.back();
        wek.pop_back();

        for (int j=0; j<n; j++)
        {
            dfts[j]=dftn[j];
            dftn[j]=0;
        }

        jeden=1;
        p=n/i;

        for (int j=0; j<n; j++)
        {
            dftn[j]=dfts[(2*(j-s)+s)&n2]+jeden*dfts[(2*(j-s)+p+s)&n2];
            s++;
            if (s==p)
            {
                jeden*=omega;
                s=0;
            }
        }
    }
}

vector <int> fft(vector <int> &jed, vector <int> &dwa)
{
    int n1=potenga(jed.size()+dwa.size());
    while(jed.size()<n1)
    {
        jed.push_back(0);
    }
    while(dwa.size()<n1)
    {
        dwa.push_back(0);
    }

    complex <double> omega(cos(2.0*PI/n1), sin(2.0*PI/n1));

    for (int i=0; i<n1; i++)
    dftn[i]=jed[i];
    dft(n1, omega);
    for (int i=0; i<n1; i++)
    pom[i]=dftn[i];

    for (int i=0; i<n1; i++)
    dftn[i]=dwa[i];
    dft(n1, omega);
    for (int i=0; i<n1; i++)
    dftn[i]*=pom[i];

    dft(n1, complex <double>(1.0, 0)/omega);

    vector <int> ret;

    for (int i=0; i<n1; i++)
    {
        ret.push_back(llround(dftn[i].real()/n1));
    }
    return ret;
}

int n, m, k;
char wcz1[1000007];
char wcz2[1000007];

char lit;

int sum[1000007];
int wyn;

void licz()
{
    vector <int> jed, dwa, bier;
    for (int i=0; i<n; i++)
    jed.push_back(0);
    for (int i=0; i<n; i++)
    {
        if (wcz1[i]!=lit)
        continue;
        jed[max(0, i-k)]++;
        if (i+k+1<n)
        jed[i+k+1]--;
    }
    for (int i=1; i<n; i++)
    jed[i]+=jed[i-1];
    for (int i=0; i<n; i++)
    jed[i]=min(jed[i], 1);
    for (int i=0; i<m; i++)
    dwa.push_back(wcz2[i]==lit);
    bier=fft(jed, dwa);
    for (int i=m-1; i<n+m-1; i++)
    sum[i-m+1]+=bier[i];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", wcz1);
    scanf("%s", wcz2);
    reverse(wcz2, wcz2+m);
    lit='A';
    licz();
    lit='T';
    licz();
    lit='G';
    licz();
    lit='C';
    licz();
    for (int i=0; i<n; i++)
    wyn+=(sum[i]==m);
    printf("%d\n", wyn);
    return 0;
}