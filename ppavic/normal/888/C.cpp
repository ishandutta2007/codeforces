#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long int llint;
typedef pair<int, int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MDO = 1e9 + 7;

int n;
string s;
vector < int > poz[30];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    for(int j = 0;j<26;j++){
        poz[j].push_back(-1);
    }
    for(int i = 0;i<n;i++){
        poz[s[i] - 'a'].push_back(i);
    }
    for(int j = 0;j<26;j++){
        poz[j].push_back(n);
    }
    int sol = INF;
    for(int i = 0;i<26;i++){
        if(poz[i].size() == 1) continue;
        int dis = 0;
        for(int j = 0;j<poz[i].size()-1;j++){
            dis = max(poz[i][j+1]-poz[i][j],dis);
        }
        sol = min(sol,dis);
    }
    printf("%d\n",sol);
    return 0;
}