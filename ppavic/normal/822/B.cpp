#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

using namespace std;

int n,m,sol = INF;
string a,b;
vector < int > pot,pri;

int main(){
    cin >> n >> m;
    cin >> a >> b;
    for(int i = 0;i<m-n+1;i++){
        int cnt = 0;
        pri.clear();
        for(int j = i;j<i+n;j++){
            if(b[j] != a[j-i]) {
                cnt++;
                pri.push_back(j-i+1);
            }
        }
        if(cnt < sol){
            sol = cnt;
            pot = pri;
        }
    }
    printf("%d\n",sol);
    for(int i = 0;i<sol;i++){
        printf("%d ",pot[i]);
    }
    printf("\n");
}