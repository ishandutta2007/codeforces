#include<bits/stdc++.h>
using namespace std;
int a[100009];
int pos[100009],R[100009];
vector<int> v[100009], ns[100009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tn=0; tn<T; tn++){
        int n, m;
        vector<int> t;
        vector<pair<int,int> > st;
        cin >> n >> m;
        //if(tn == 4) cout<<n<<" "<<m<<endl;
 
        for(int i = 1; i <= n; i++){
            cin >> a[i];
           // if(tn == 4) cout <<a[i]<<" ";
        }
 
       // if(tn == 4) cout<<endl;
        sort(a+1, a+n+1);
        for(int i = n - m + 1; i <= n; i++){
            t.push_back(a[i]);
        }
 
        for(int i = 0; i < m; i++){
            int k;
            cin >> k;
            //if(tn == 4) cout<<k<<" ";
            long long s = 0;
            for(int j = 0; j < k; j++){
                int x;
                cin >> x;
               // if(tn == 4) cout<<x<<" ";
                v[i].push_back(x);
                s += x;
            }
           // if(tn == 4) cout<<endl;
            st.push_back({(s + k - 1) / k, i});
            for(int j = 0; j < k; j++){
                ns[i].push_back((s - v[i][j] + k - 2) / (k - 1));
            }
        }
        sort(st.begin(), st.end());
        string ans = "";
        int j = 0;
        set<int> bad, good;
        int BAD = 0;
        for(int i = 0; i < m; i++){
 
            while(j < m && t[j] < st[i].first) j++;
            R[i] = j;
           // cout<<i<<" "<<j<<endl;
            pos[st[i].second] = i;
            if(R[i] > i + 1){
                for(int i = 0; i < m; i++)
                    for(int j = 0; j < v[i].size(); j++)
                        cout<<'0';
                cout<<endl;
                BAD = 1;
                break;
            }
            if(R[i] == i) good.insert(i);
            if(R[i] == i+1) bad.insert(i);
        }
        if(!BAD){
        for(int i = 0; i < m; i++){
            int p = pos[i];
            for(int j = 0; j < ns[i].size(); j++){
                int x = ns[i][j];
                //st[p] <-- x
                int nr = lower_bound(t.begin(), t.end(), x) - t.begin();
                // 1 2 3 4 5
 
                int np = (lower_bound(R, R+m, nr) - R);
                if(np > p) np--;
                if(np > p){
                    if(bad.size()) ans += '0';
                    else{
                        if(nr > np) ans += '0';
                        else if(good.lower_bound(p+1) != good.end() && *good.lower_bound(p+1) <= np){
                            ans += '0';
                        }
                        else ans += '1';
                    }
                }
                else{
                    if(nr > np) ans += '0'; else
                    if(!bad.size()) ans += '1';
                    else if(*bad.begin() >= np && *(--bad.end()) <= p) ans += '1';
                    else ans += '0';
                }
            }
            //R[p] <-- x
        }
            cout<<ans<<endl;
        }
        for(int i = 0; i <= n; i++)
            v[i].clear(), ns[i].clear(), pos[i] = 0, R[i] = 0, a[i] = 0;
 
    }
 
}
/*
1
5 5
112 114 118 120 122
3 1 123 122
3 1 122 123
3 1 122 123
3 1 123 122
3 1 123 123
*/