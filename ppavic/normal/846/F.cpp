#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 50;

typedef long long int llint;

vector < int > v[N];
int n,x;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<N;i++){
        v[i].push_back(0);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&x);
        v[x].push_back(i);
    }
    for(int i = 0;i<N;i++){
        v[i].push_back(n + 1);
    }
    llint uk = (llint)n * (llint)n;
    llint sol = 0;
    for(int i = 0;i<N;i++){
        llint kol = 0;
        for(int j = 0;j<v[i].size() - 1;j++){
            llint br = (llint)v[i][j + 1] - (llint)v[i][j] - 1;
            kol += br * br;
        }
        sol += uk - kol;
    }
    cout << (long double)sol / (long double)uk << endl;
}