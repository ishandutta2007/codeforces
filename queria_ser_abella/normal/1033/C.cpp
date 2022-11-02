#include <bits/stdc++.h>
#define maxn 200200
#define pb push_back
#define pii pair<int,int>
#define debug
typedef long long ll;
using namespace std;

int v[maxn];
int ls[maxn];

int main(){
    int n;
    scanf("%d",&n);
    vector<pii> a;
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        a.pb(pii(v[i],i));   
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int pos = a[i].second;
        int val = a[i].first;
        int ok = 0;
        for(int j=pos;j<n;j+=val)
            if(v[j] > val && ls[j]) ok = 1;
        for(int j=pos;j>=0;j-=val)
            if(v[j] > val && ls[j]) ok = 1;
        if(!ok)
            ls[pos] = 1;
    }
    for(int i=0;i<n;i++)
        printf("%c",ls[i]?'B':'A');
}