#include <bits/stdc++.h>
using namespace std;

/* FFT dla doubli O(n*log(n))                                                 */
/* wynik mnozenia dwoch wielomianow                                           */
/* argumenty to dwa wektory, wynik to jeden wektor                            */
/* fft() dziala bezpiecznie dla liczb do 35k                                  */
/* dla wiekszych odpalamy fft_dokladne, dziala wolniej, ale liczy dokladnie   */
/* mozna je zmodyfikowac do liczenia modulo np. 10^9+7                        */
/* sprawdzic, czy argumenty nie powinny byc wektorami long longow             */

struct fft_double
{
	double PI=3.141592653589793;

	vector < complex <double> > dftn; //poczebne
	vector < complex <double> > dfts; //poczebne

	vector < complex <double> > pom; //do zwyklego

	vector < complex <double> > a1; //do dokladnego
	vector < complex <double> > a2; //do dokladnego
	vector < complex <double> > b1; //do dokladnego
	vector < complex <double> > b2; //do dokladnego

	vector <double> cosi; //poczebne
	vector < complex <double> > omega; //poczebne
	fft_double(){}
	fft_double(int n, int chce_dokladne)
	{
		n=potenga(n);
		dftn.resize(n+1, 0);
		dfts.resize(n+1, 0);
		
		pom.resize(n+1, 0);
		
		if (chce_dokladne)
		{
			a1.resize(n+1, 0);
			a2.resize(n+1, 0);
			b1.resize(n+1, 0);
			b2.resize(n+1, 0);
		}
		
		cosi.resize(n+1, 0);
		omega.resize(n+1, 0);
	}

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

	inline void dft(int n, int kier)
	{
		int n2=n-1;
		int s=0;
		int p;
		int g;

		for (int i=2; i<=n; i<<=1)
		{
			dftn.swap(dfts);

			p=n/i;

			if (kier)
			{
				g=0;
				for (int j=0; j<n; j++)
				{
					dftn[j]=dfts[(2*(j-s)+s)&n2]+omega[g]*dfts[(2*(j-s)+p+s)&n2];
					s++;
					if (s==p)
					{
						g=j+1;
						s=0;
					}
				}
			}
			else
			{
				g=n;
				for (int j=0; j<n; j++)
				{
					dftn[j]=dfts[(2*(j-s)+s)&n2]+omega[g]*dfts[(2*(j-s)+p+s)&n2];
					s++;
					if (s==p)
					{
						g=n-j-1;
						s=0;
					}
				}
			}
		}
	}

	void licz_omegi(int n1)
	{
		double kat=2.0*PI/n1;
		int n2=n1-1;
		int dod=3*n1/4;

		for (int i=0; i<=n1; i++)
			cosi[i]=cos(kat*i);
		for (int i=0; i<=n1; i++)
			omega[i]=complex <double> (cosi[i], cosi[(i+dod)&n2]);
	}

	vector <int> fft(vector <int> &jed, vector <int> &dwa)
	{
		int n1=potenga(jed.size()+dwa.size());

		licz_omegi(n1);

		for (int i=0; i<jed.size(); i++)
			dftn[i]=jed[i];
		for (int i=jed.size(); i<n1; i++)
			dftn[i]=0;
		dft(n1, 1);
		for (int i=0; i<n1; i++)
			pom[i]=dftn[i];

		for (int i=0; i<dwa.size(); i++)
			dftn[i]=dwa[i];
		for (int i=dwa.size(); i<n1; i++)
			dftn[i]=0;
		dft(n1, 1);
		for (int i=0; i<n1; i++)
			dftn[i]*=pom[i];

		dft(n1, 0);

		vector <int> ret;

		for (int i=0; i<n1; i++)
			ret.push_back(llround(dftn[i].real()/n1));
		return ret;
	}

	vector <int> fft_dokladne(vector <int> &jed, vector <int> &dwa)
	{
		int n1=potenga(jed.size()+dwa.size());

		licz_omegi(n1);

		long long M=32000;

		for (int i=0; i<jed.size(); i++)
			dftn[i]=jed[i]/M;
		for (int i=jed.size(); i<n1; i++)
			dftn[i]=0;
		dft(n1, 1);
		for (int i=0; i<n1; i++)
			a1[i]=dftn[i];

		for (int i=0; i<jed.size(); i++)
			dftn[i]=jed[i]%M;
		for (int i=jed.size(); i<n1; i++)
			dftn[i]=0;
		dft(n1, 1);
		for (int i=0; i<n1; i++)
			b1[i]=dftn[i];

		for (int i=0; i<dwa.size(); i++)
			dftn[i]=dwa[i]/M;
		for (int i=dwa.size(); i<n1; i++)
			dftn[i]=0;
		dft(n1, 1);
		for (int i=0; i<n1; i++)
			a2[i]=dftn[i];

		for (int i=0; i<dwa.size(); i++)
			dftn[i]=dwa[i]%M;
		for (int i=dwa.size(); i<n1; i++)
			dftn[i]=0;
		dft(n1, 1);
		for (int i=0; i<n1; i++)
		b2[i]=dftn[i];

		vector <int> ret;
		for (int i=0; i<n1; i++)
		ret.push_back(0);

		for (int i=0; i<n1; i++)
			dftn[i]=a1[i]*a2[i];
		dft(n1, 0);
		for (int i=0; i<n1; i++)
			ret[i]+=llround(dftn[i].real()/n1)*M*M;

		for (int i=0; i<n1; i++)
			dftn[i]=a1[i]*b2[i]+b1[i]*a2[i];
		dft(n1, 0);
		for (int i=0; i<n1; i++)
			ret[i]+=llround(dftn[i].real()/n1)*M;

		for (int i=0; i<n1; i++)
			dftn[i]=b1[i]*b2[i];
		dft(n1, 0);
		for (int i=0; i<n1; i++)
			ret[i]+=llround(dftn[i].real()/n1);

		return ret;
	}

};

fft_double janusz=fft_double(400000, 0);

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
    bier=janusz.fft(jed, dwa);
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