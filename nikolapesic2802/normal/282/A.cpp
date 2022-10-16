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

ll h(vector<int> a)
{
    ll hh=0;
    for(auto p:a)
        hh=hh*501+p;
    return hh;
}
int main()
{
    int n;
    scanf("%i",&n);
    int x=0;
    while(n--)
    {
        string s;
        cin >> s;
        if(s[1]=='-')
            x--;
        else
            x++;
    }
    printf("%i\n",x);
    return 0;
    for(int c=1;c<23;c++){
        FILE *f;
        string s="case-";
        if(c<10)
            s+='0';
        s+=to_string(c);
        FILE *in,*out;
        string s1=s+".in";
        in=fopen(s1.c_str(),"r");
        s+=".out";
        out=fopen(s.c_str(),"r");
        int tim=clock();



        unordered_map<ll,int> cnt;
        int n,k,m;
        fscanf(in,"%i %i %i",&n,&k,&m);
        for(int i=0;i<n;i++)
        {
            vector<int> karta(k);
            for(int j=0;j<k;j++)
                fscanf(in,"%i",&karta[j]);
            sort(all(karta));
            for(int mask=1;mask<(1<<k);mask++)
            {
                vector<int> tr;
                for(int j=0;j<k;j++)
                    if(mask&(1<<j))
                        tr.pb(karta[j]);
                cnt[h(tr)]++;
            }
        }
        bool correct=true;
        int q;
        fscanf(in,"%i",&q);
        while(q--)
        {
            vector<int> tr;
            for(int i=0;i<k;i++)
            {
                int a;
                fscanf(in,"%i",&a);
                tr.pb(a);
                sort(all(tr));
                int sol;
                //printf("%lld\n",cnt[h(tr)]);
                fscanf(out,"%i",&sol);
                if(sol!=cnt[h(tr)])
                    correct=false;
            }
        }




        printf("Test primer %i: ",c);
        if(correct)
            printf("Tacno! ");
        else
            printf("NETACNO! ");
        printf("%ims\n",clock()-tim);
    }
    return 0;
}