#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1e5;
string match[N];
vector<int> T[N];
int deg[N];

int compr(string v){ // v is length of two
    int n1 = v[0] - 48;
    int n2 = v[1] - 48;
    int s = n1 * 90 + n2;
    match[s] = v;
    return s ;
}

void NO(){
    cout << "NO";
    exit(0);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    string t;
    int n1, n2;
    for(int i = 0 ; i < n; i ++ ){
        cin >> t;
        n1 = compr(t.substr(0,2));
        n2 = compr(t.substr(1,2));
        T[n1].push_back(n2);
        deg[n2] ++ ;
    }
    int ci = -1, cj = -1;
    int vl = -1;
    for(int i = 0 ; i < N ; i ++ ){
        if(T[i].size() + deg[i] == 0)
            continue;
        vl = i;
        if(deg[i] == T[i].size())
            continue;
        if(deg[i] > T[i].size()){
            if(cj != -1 || deg[i] - T[i].size() > 1) NO();
            cj = i;
        }
        if(T[i].size() > deg[i]){
            if(ci != -1 || T[i].size() - deg[i] > 1) NO();
            ci = i;
        }
    }
    if(ci != -1 || cj != -1){
        if(ci == -1 || cj == -1) NO();
    }
    if(ci == -1) ci = vl;
    vector<int> tour;
    vector<int> curv;
    curv.push_back(ci);
    int tp;
    int nx;
    while(!curv.empty()){
        tp = curv.back();
        //break;
        if(!T[tp].empty()){
            nx = T[tp].back();
            T[tp].pop_back();
            curv.push_back(nx);
        }
        else{
            tour.push_back(tp);
            curv.pop_back();
        }
    }
    if(tour.size() != n+1){
         NO();
    }
    cout << "YES\n";
    reverse(tour.begin(), tour.end());
    cout << match[tour[0]][0];
    for(auto p : tour){
        cout << match[p][1];
    }
    return 0;
}