#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

bool check(string a,string b){
    return a.size()>b.size();
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    string al[n];
    unordered_map<string,int>val;
    string c;
    for(int j = 0;j<n;j++){
        cin >> al[j];
        for(int i = 0;i<9;i++){
            for(int x = i;x<9;x++){
                c+=al[j][x];
                if(val[c]==0) val[c] = j+1;
                else if(val[c] != j+1) val[c] = -1;
            }
            c.clear();
        }
    }
    string rez;
    for(int j = 0;j<n;j++){
        rez = al[j];
        for(int i = 0;i<9;i++){
            for(int x = i;x<9;x++){
                c += al[j][x];
                if(val[c]==-1)continue;
                if(check(rez,c)){
                    rez = c;
                }
            }
            c.clear();
        }
        cout << rez << "\n";
    }
    return 0;
}