#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
#define bst bitset<40>
int ans;
bst N[40],empty;
int n;
void BKB(bst R,bst P)
{
    if(P==empty)
    {
        ans=max(ans,(int)R.count());
        return;
    }
    if((R|P).count()<=ans) return ;
    int u;
    for(int i=0;i<n;i++)
        if(P[i])
        {
            u=i;
            break;
        }
    bst now=P&~N[u];
    for(int i=0;i<n;i++)
    {
        if(now[i])
        {
            R[i]=1;
            BKB(R,P&N[i]);
            R[i]=0;
            P[i]=0;
        }
    }
}
const unsigned int seed = 1635274098u;
const int numIterations = 20;     // Ovoliko puta cemo pozvati maxClique, svaki put za novi slucajni graf.
const int nMax = 100;

                            // Broj cvorova grafa.
bool connected[nMax][nMax];       // connected[p][q] da li postoji grana izmedju cvorova p i q.


// ====== Pocetak vaseg koda ======

struct Vertex {
    int k;         // Oznaka
    int degree;    // Broj suseda
};

bool compareVertices(const Vertex &u , const Vertex &v) {
    return u.degree > v.degree;
}


bool c[nMax][nMax];              // c[i][j] = da li su cvor i i cvor j povezani
int cliqueNeighborCount[nMax];   // cliqueNeighborCount[i] = koliko cvor i ima suseda u trenutnoj kliki.
int cliqueSize;                  // velicina trenutne klike
int maxCliqueSize;               // velicina najvece pronadjene klike do sad

// Pozivanjem funkcije find(k) smatramo da smo cvorove sa oznakama vecim od k vec odredili da li su u kliki
// ili ne, i sada zelimo da odredimo za k-ti.
void find(int k) {
    if (cliqueSize > maxCliqueSize)
        maxCliqueSize = cliqueSize;

    if (k < 0)
        return;

    // Probamo da ubacimo k-ti samo ako su svi cvorovi iz trenutne klike susedi cvoru k
    if (cliqueNeighborCount[k] == cliqueSize) {
        // Svim susedima od k povecavamo broj suseda u trenutnoj kliki (jer k dodajemo u kliku).
        // Sa p brojimo koliko ima onih koji su sada susedi svim cvorovima u novoj kliki (stara klika + k-ti).
        int p = 0;
        for (int i = 0; i < k; i++)
            if (c[k][i]) {
                if (cliqueNeighborCount[i] == cliqueSize)
                    p++;
                cliqueNeighborCount[i]++;
            }

        // Odsecamo ako vidimo da nije moguce poboljsati, tj. radimo samo ako velicina trenutne klike plus
        // broj svih onih koji su povezani sa svima iz trenutne klike i sa k plus 1 (za k) je vece od najbolje
        // do sada pronadjene klike.
        if (cliqueSize + p + 1 > maxCliqueSize) {
            cliqueSize++;
            find(k-1);
            cliqueSize--;
        }

        // Vracamo stanje na kako je bilo pre ubacivanja k-tog
        for (int i = 0; i < k; i++)
            if (c[k][i])
                cliqueNeighborCount[i]--;
    }

    // Probamo da ne ubacimo k-ti samo ako bez njega mozemo poboljsati velicinu.
    if (cliqueSize + k > maxCliqueSize)
        find(k-1);
}


int maxClique() {
    // Inicijalizovanje cvorova i brojanje suseda
    Vertex vertices[n];

    for (int i = 0; i < n; i++) {
        vertices[i].k = i;
        vertices[i].degree = 0;
        for (int j = 0; j < n; j++)
            if (connected[i][j])
                vertices[i].degree++;
    }

    // Sortiranje opadajuce po broju suseda, ali prolaz kroz cvorove cemo raditi odnazad.
    sort(vertices, vertices + n, compareVertices);

    // Pretumbavanje matrice tako da redosled u matrici odgovara sortiranom redosledu
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = connected[vertices[i].k][vertices[j].k];

    for (int i = 0; i < n; i++)
        cliqueNeighborCount[i] = 0;

	cliqueSize = 0;
	maxCliqueSize = 0;
	find(n-1);
	return maxCliqueSize;
}
int main()
{
	int n1,m1;
	scanf("%i %i",&n1,&m1);
	map<string,int> mapa;
	map<string,int> number;
	int tr=1;
	vector<vector<int> > moze;
	for(int i=0;i<n1;i++)
    {
        int t;
        scanf("%i",&t);
        if(t==1)
        {
            vector<int> mo(m1);
            for(auto p:mapa)
            {
                mo[p.s]=1;
            }
            moze.pb(mo);
            mapa.clear();
        }
        else
        {
            string s;
            cin >> s;
            if(number[s]==0)
                number[s]=tr,tr++;
            mapa[s]=number[s]-1;
        }
    }
    vector<int> mo(m1);
    for(auto p:mapa)
    {
        mo[p.s]=1;
    }
    moze.pb(mo);
    n=m1;
    int m=moze.size();
    vector<bitset<(int)1e5+5> > bit(n);
    for(int j=0;j<moze.size();j++)
    {
        vector<int> p=moze[j];
        assert(p.size()==m1);
        for(int i=0;i<p.size();i++)
        {
            if(p[i]==1)
                bit[i][j]=1;
        }
    }
    bst x;
    for(int i=0;i<n;i++)
    {
        x[i]=1;
        for(int j=0;j<n;j++)
        {
            if((bit[i]^bit[j])==(bit[i]|bit[j])){
                connected[i][j]=1;
            }
        }
    }
    maxClique();
    printf("%i\n",maxCliqueSize);
    return 0;
}