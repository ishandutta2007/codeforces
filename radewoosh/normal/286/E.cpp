#include <bits/stdc++.h>
using namespace std;

//WYLEWIE
//PODAJESZ 2 WEKTORY INTW
//WYCHODZI CI JEDEN Z WYNIKEM
//NA POCZTKU MAINA RAZ DPAL szykuj()
//POTEM JU TYLKO UYWASZ fft()
//WEKTOR Z WYNIKIEM BDZIE WIKSZY NI PODANE, NAWET NI ICH SUMARYCZNA WIELKO

double PI=3.141592653589793;

vector < complex <double> > duzywek;
vector < complex <double> > duzyret[50][2];

void szykuj()
{
    for (int j=0; j<22; j++)
    {
        for (int i=1; i<=(1<<(21-j)); i++)
        {
            duzyret[j][0].push_back(0);
            if (j)
            duzyret[j][1].push_back(0);
        }
    }
}

int potenga(int v)
{
    for (int i=1; 1; i<<=1)
    {
        if (i>=v)
        {
            return i;
        }
    }
}

void dft(int nn, int kt, int coile, complex <double> omega, int gdzie, int poz)
{
    if (nn==1)
    {
        duzyret[poz][gdzie][0]=duzywek[kt];
        return;
    }

    dft(nn>>1, kt, coile<<1, omega*omega, 0, poz+1);
    dft(nn>>1, kt+coile, coile<<1, omega*omega, 1, poz+1);

    complex <double> jeden (1.0, 0.0);

    int w=0;

    int an=(nn>>1)-1;

    for (int i=0; i<nn; i++)
    {
        duzyret[poz][gdzie][i]=duzyret[poz+1][0][i&an]+jeden*duzyret[poz+1][1][i&an];
        jeden*=omega;
    }
}

vector <int> fft(vector <int> jed, vector <int> dwa)
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

    complex <double> omega (cos(2.0*PI/n1), sin(2.0*PI/n1));

    vector < complex <double> > pam;
    duzywek.clear();

    for (int i=0; i<n1; i++)
    {
        duzywek.push_back(complex <double> (jed[i], 0.0));
    }

    dft(n1, 0, 1, omega, 0, 0);
    pam=duzyret[0][0];

    for (int i=0; i<n1; i++)
    {
        duzywek[i]=complex <double> (dwa[i], 0.0);
    }

    dft(n1, 0, 1, omega, 0, 0);

    for (int i=0; i<n1; i++)
    {
        duzywek[i]=pam[i]*duzyret[0][0][i];
    }

    omega=( complex <double> (1.0, 0.0) )/omega;

    dft(n1, 0, 1, omega, 0, 0);

    vector <int> retret;
    int dowrzucenia;

    for (int i=0; i<n1; i++)
    {
        duzyret[0][0][i]/=n1;
        dowrzucenia=round(duzyret[0][0][i].real());

        retret.push_back(dowrzucenia);
    }
    return retret;
}

int n, m;
vector <int> dopo;
vector <int> otrz;

vector <int> wyn;


int x;

int main()
{
    szykuj();
    scanf("%d%d", &n, &m);
    while(dopo.size()<=m)
    {
        dopo.push_back(0);
    }
    dopo[0]=1;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        dopo[x]=1;
    }
    otrz=fft(dopo, dopo);
    while(otrz.size()>m+1)
    otrz.pop_back();
    for (int i=1; i<otrz.size(); i++)
    {
        if (otrz[i] && !dopo[i])
        {
            printf("NO");
            return 0;
        }
        if (otrz[i]==2)
        {
            wyn.push_back(i);
        }
    }
    printf("YES\n");
    printf("%d\n", (int) wyn.size());
    for (int i=0; i<wyn.size(); i++)
    {
        printf("%d ", wyn[i]);
    }
    return 0;
}