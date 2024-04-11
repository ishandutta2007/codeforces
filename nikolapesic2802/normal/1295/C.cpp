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
                string s, t;

                cin >> s;
                cin >> t;

                set<char> us, ut;

                for(ll i = 0; i < s.length(); i++)
                {
                    us.insert(s[i]);
                }

                for(ll i = 0; i < t.length(); i++)
                {
                    ut.insert(t[i]);
                }

                bool moze = true;

                for(auto i = ut.begin(); i != ut.end(); i++)
                {
                    if(us.find(*i) == us.end())
                    {
                        moze = false;
                        break;
                    }
                }
                ll n = s.length();
                if(!moze)
                {
                    cout << "-1" << endl;
                    continue;
                }

                ll m[28][n+10];

                for(int i = 0; i <= 27; i++)
                {
                    for(int j = 0; j <= n; j++)
                        m[i][j]=-1;
                }

                ll last[28];

                for(int y = 0; y < 28; y++)
                    last[y] = 0;

                for(ll i = 0; i < s.length(); i++)
                {
                    //cout << i << endl;
                    for(ll y = last[s[i]-'a']; y <=i; y++)
                    {
                        m[s[i]-'a'][y] = i;
                        last[s[i]-'a']=i+1;

                        //cout <<i << "  " << y << endl;
                    }
                }

                //cout << "aaaaaaaaaaaaaaa";

                for(ll i = 0; i < 27; i++)
                {
                    if(last[i] < n)
                    {
                        for(ll j = last[i]; j < n; j++)
                        {
                            m[i][j] = -1;
                        }
                    }
                }
                
                

               /* for(int i = 0; i < 27; i++)
                {
                    cout << (char)('a' + i) << ":  ";
                    for(int j = 0; j < n; j++)
                    {
                        cout << m[i][j] << " "; 
                    }
                    cout << endl;
                    //cout << "bbbbbbbbbb ";
                }*/

                

                ll rez = 1;
                ll current = 0;

                for(ll i = 0; i < t.length(); i++)
                {
                    if(m[t[i]-'a'][current] < current)
                    {
                        rez++;
                        current = 0;
i--;
                    }

                    else
                    {
                        current = m[t[i]-'a'][current] +1;
                        if(current > n-1 && i != t.length()-1)
                        {
                            current = 0;
                            rez++;
                        }
                    }
                    
                }

                cout << rez << endl;


        }

        return 0;
    }