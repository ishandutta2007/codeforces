#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define IMAX INT_MAX
#define IMIN INT_MIN

const ld PI = acos(-1);
const ll MOD = ll(1e9) + 7;

const int N = (int)2e5 + 9;
int n,tim;
int maxs[N];
int req[N];

bool can(int k){
    vector<int>ti;
    for(int i = 0;i<n;i++)
        if(k<=maxs[i])ti.push_back(req[i]);
    sort(ti.begin(),ti.end());
    if(ti.size()<k)return false;
    int cur = 0;
    for(int x = 0;x<k;x++)cur += ti[x];
    if(cur>tim)return false;
    return true;
}

int main(){
    scanf("%d %d",&n,&tim);
    for(int i = 0;i<n;i++)
        scanf("%d %d",&maxs[i],&req[i]);
    int l = 0,r = n+9,m;
    while(r-l>1){
        m = (r+l)/2;
        if(can(m))l=m;
        else r=m;
    }
    printf("%d\n%d\n",l,l);
    vector<pair<int,int>>take;
    for(int i = 0;i<n;i++){
        if(maxs[i]>=l)take.push_back(mp(req[i],i+1));
    }
    sort(take.begin(),take.end());
    for(int i = 0;i<l;i++){
        printf("%d ",take[i].se);
    }
    return 0;
}