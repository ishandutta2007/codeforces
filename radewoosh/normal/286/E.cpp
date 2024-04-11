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
	fft_double(int n, int chce_dokladne)//n to maksymalna suma rozmiarow mnozonych wielomianow
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
			dftn[i]*=dftn[i];

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

int n, m;

vector <int> d1, d2;
vector <int> wyn;

int main()
{
	scanf("%d%d", &n, &m);
	d1.resize(m+1, 0);
	d1[0]=1;
	for (int i=1; i<=n; i++)
	{
		int p1;
		scanf("%d", &p1);
		d1[p1]=1;
	}
	fft_double janusz=fft_double(d1.size()*2, 0);
	d2=janusz.fft(d1, d1);
	for (int i=0; i<=m; i++)
	{
		if ((!d1[i])!=(!d2[i]))
		{
			printf("NO\n");
			return 0;
		}
		if (d2[i]==2)
		{
			wyn.push_back(i);
		}
	}
	printf("YES\n");
	printf("%d\n", (int)wyn.size());
	for (int i=0; i<wyn.size(); i++)
		printf("%d ", wyn[i]);
	printf("\n");
    return 0;
}