    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    #define ll int
    #define pb push_back
    #define mp make_pair
    #define f first
    #define s second
    #define sz(x) (int)x.size()
    #define all(x) x.begin(), x.end()
     
    using namespace std;
    using namespace __gnu_pbds;
     
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
    template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
    template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
    template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
     

void fastscan(int &number)
{
    char c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
void write(ll i)
{
    if(i>9)
        write(i/10);
    putchar(i%10+48);
}


        ll brSuseda[100050];
    int main()
    {
	    ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	
        int n;
        fastscan(n);

        vector<ll> ne[100050];
        vector<ll> res(n+10);
        //map<int,int> id[n+10];
        vector<pair<int,int>> id[n+10]; //first - susedId, second - edgeId
        
        

        for(int i = 0; i < n-1; i++)
        {
            ll a,b;
            fastscan(a);
fastscan(b);

            ne[a].push_back(b);
            ne[b].push_back(a);
            id[a].push_back(make_pair(b, i));
            id[b].push_back(make_pair(a, i));
            //id b a
            brSuseda[a]++;
            brSuseda[b]++;

        }

         for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < ne[i].size(); j++)
            {                               
                res[id[i][j].second] = -1;                   
            }
        }

        ll broj=0;

        for(int i = 1; i <= n; i++)
        {
            //cout << *i<<" brSuseda " << brSuseda[*i] << endl;
            if(ne[i].size() == 1 && res[id[i][0].second] == -1)
            {               
                res[id[i][0].second] = broj;
                ////cout << "LIST " << i << " " <<ne[i][0] <<  "  ubacujem " << broj << endl;
                 broj++;
            }
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < ne[i].size(); j++)
            {
                if(res[id[i][j].second] == -1)
                {                    
                    res[id[i][j].second] = broj;
                    broj++;
                }
            }
        }

        for(int i = 0; i < n-1; i++)
        {
            write(res[i]);
putchar('\n');
        }

        return 0;
    }