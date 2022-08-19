//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

struct fft_double {
  double PI = 3.141592653589793;
  using Complex = complex<double>;

  vector<Complex> dftn;
  vector<Complex> dfts;

  vector<Complex> pom;

  vector<Complex> a1;
  vector<Complex> a2;
  vector<Complex> b1;
  vector<Complex> b2;

  vector<double> cosi;
  vector<Complex> omega;

  fft_double() {}

  // @n to maksymalna suma rozmiarw mnoonych wielomianw.
  fft_double(int n, bool chce_dokladne) {
    n = potenga(n);
    dftn.resize(n + 1, 0);
    dfts.resize(n + 1, 0);
    pom.resize(n + 1, 0);
    if (chce_dokladne) {
      a1.resize(n + 1, 0);
      a2.resize(n + 1, 0);
      b1.resize(n + 1, 0);
      b2.resize(n + 1, 0);
    }
    cosi.resize(n + 1, 0);
    omega.resize(n + 1, 0);
  }

  inline int potenga(int v) {
    for (int i = 1; ; i *= 2) {
      if (i >= v) {
        return i;
      }
    }
    assert(false);
  }

  inline void dft(int n, int kier) {
    int n2 = n - 1;
    int s = 0;
    int p;
    int g;
    for (int i = 2; i <= n; i *= 2) {
      dftn.swap(dfts);
      p = n / i;
      if (kier) {
        g = 0;
        for (int j = 0; j < n; j++) {
          dftn[j] = dfts[(2 * (j - s) + s) & n2] +
                    omega[g] * dfts[(2 * (j - s) + p + s) & n2];
          s++;
          if (s == p) {
            g = j + 1;
            s = 0;
          }
        }
      } else {
        g = n;
        for (int j = 0; j < n; j++) {
          dftn[j] = dfts[(2 * (j - s) + s) & n2] +
                    omega[g] * dfts[(2 * (j - s) + p + s) & n2];
          s++;
          if (s == p) {
            g = n - j - 1;
            s = 0;
          }
        }
      }
    }
  }

  void licz_omegi(int n1) {
    double kat = 2.0 * PI / n1;
    int n2 = n1 - 1;
    int dod = 3 * n1 / 4;
    for (int i = 0; i <= n1; i++)
      cosi[i] = cos(kat * i);
    for (int i = 0; i <= n1; i++)
      omega[i] = Complex(cosi[i], cosi[(i + dod) & n2]);
  }

  vector<int> fft(vector<int> &jed, vector<int> &dwa) {
    int n1 = potenga(jed.size() + dwa.size());
    licz_omegi(n1);
    for (int i = 0; i < (int) jed.size(); i++)
      dftn[i] = jed[i];
    for (int i = (int) jed.size(); i < n1; i++)
      dftn[i] = 0;
    dft(n1, 1);
    for (int i = 0; i < n1; i++)
      pom[i] = dftn[i];
    for (int i = 0; i < (int) dwa.size(); i++)
      dftn[i] = dwa[i];
    for (int i = (int) dwa.size(); i < n1; i++)
      dftn[i] = 0;
    dft(n1, 1);
    for (int i = 0; i < n1; i++)
      dftn[i] *= pom[i];
    dft(n1, 0);
    vector<int> ret;
    for (int i = 0; i < n1; i++)
      ret.push_back(llround(dftn[i].real() / n1));
    return ret;
  }
};

const int nax=1000*1007;

int n;
char wcz[nax];
int tab[nax];

fft_double janusz(1000*1000, false);

int zle[nax];

vector <int> wyn;

vector <int> raz, dwa, res;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%s", &n, wcz);
		wyn.clear();
		for (int i=0; i<n; i++)
		{
			if (wcz[i]=='V')
				tab[i]=0;
			if (wcz[i]=='K')
				tab[i]=1;
			if (wcz[i]=='?')
				tab[i]=2;
		}
		
		raz.clear();
		raz.resize(n);
		dwa.clear();
		dwa.resize(n);
		for (int i=1; i<=n; i++)
			zle[i]=0;
		for (int i=0; i<n; i++)
			raz[i]=dwa[i]=0;
		for (int i=0; i<n; i++)
		{
			if (tab[i]==0)
				raz[i]=1;
			if (tab[i]==1)
				dwa[n-1-i]=1;
		}
		
		res=janusz.fft(raz, dwa);
		
		debug() << res;
		
		for (int i=0; i<(int)res.size(); i++)
			if (res[i])
				zle[abs(n-1-i)]=1;
		
		for (int i=1; i<=n; i++)
		{
			for (int j=i; j<=n; j+=i)
				zle[i]|=zle[j];
			if (!zle[i])
				wyn.push_back(i);
		}
		
		printf("%d\n", (int)wyn.size());
		for (int i : wyn)
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}