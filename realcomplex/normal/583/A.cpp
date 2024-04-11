#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    int n;
    cin >> n;
    map<int,int>hor;
    map<int,int>col;
    int a,b;
    for(int j = 1;j<=n*n;j++){
        cin >> a >> b;
        if(hor[a] == 0 && col[b] == 0){
            cout << j << " ";
            hor[a]++;
            col[b]++;
        }
    }
    return 0;
}