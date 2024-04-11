#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e5+500;
vector <int> euklid;
int pr[N];
int a[N],n;
int prim[N];

int main(){
    memset(pr,1,sizeof(pr));
    for(int i = 2;i<N;i++){
        if(!pr[i]) continue;
        else euklid.push_back(i);
        for(int j = 2;i*j<N;j++)
            pr[i*j] = 0;
    }
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        int j = 0;
        if(binary_search(euklid.begin(),euklid.end(),a[i])) prim[a[i]]++;
        while(euklid[j] < a[i]/2+1){
            if(a[i]%euklid[j] == 0){
                prim[euklid[j]]++;
            }
            j++;
        }
    }
    int sol = 1;
    for(int i = 0;i<N;i++){
        sol = max(sol,prim[i]);
    }
    cout << sol;

}