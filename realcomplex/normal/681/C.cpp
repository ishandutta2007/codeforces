#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long
#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

signed main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    queue<pair<string,int>>oper;
    priority_queue<int,vector<int>,greater<int>>tek;
    string k;
    int v;
    for(int j = 0;j<n;j++){
        cin >> k;
        if(k == "insert"){
            cin >> v;
            tek.push(v);
            oper.push(mp(k,v));
        }
        else if(k == "removeMin"){
            if(tek.empty()){
                tek.push(-1e9);
                oper.push(mp("insert",-1e9));
            }
            tek.pop();
            oper.push(mp(k,0));
        }
        else{
            cin >> v;
            if(tek.empty() || tek.top() != v){
                while(!tek.empty()&&tek.top()<v){
                    oper.push(mp("removeMin",0));
                    tek.pop();
                }
                if(tek.empty() || tek.top() != v){
                    tek.push(v);
                    oper.push(mp("insert",v));
                }
                oper.push(mp(k,v));
            }
            else{
                oper.push(mp(k,v));

            }
        }
    }
    cout << oper.size() << "\n";
    while(!oper.empty()){
        cout << oper.front().fi << " ";
        if(oper.front().fi != "removeMin") cout << oper.front().se;
        cout << "\n";
        oper.pop();
    }
    return 0;
}