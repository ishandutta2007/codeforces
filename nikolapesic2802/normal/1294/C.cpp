    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    #define ll long long
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
     
    int main()
    {
	    ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	
        int t;

        cin >> t;
               

        while(t--)
        {
            ll n;
            cin >> n;
          

            ll a,b,c;
            bool pom = false;

            for(int i = 2; i < sqrt(n)+1; i++)
            {
                if(n%i == 0)
                {
                    a = i;
                    pom = true;
                    break;
                }
            }

            if(!pom)
            {
                cout << "NO" << endl;
                continue;
            }
            pom = false;

            for(int i = 2; i < sqrt(n)+1; i++)
            {
                if((n/a)%i == 0 &&  i!=a)
                {
                    b = i;
                    pom = true;
                    break;
                }
            }

            if(!pom)
            {
                cout << "NO" << endl;
                continue;
            }
            pom = false;
            if(n/(a*b) != a && n/(a*b) !=b && n/(a*b) >=2)
            {
                c = n/(a*b);
                pom = true;
            }
            if(pom && a*b*c==n)
            {
                cout << "YES" << endl;
                cout << a << " " << b << " " << c << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            
        }

        return 0;
    }