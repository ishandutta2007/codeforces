#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

string good[100][2];

int team[100];
int n;
const string name[7] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};

int a,b,c;

pair<int,int> calc(){
    int cnt[3];
    cnt[0]=cnt[1]=cnt[2]=0;
    pair<int,int> res=mp(0,0);
    for (int i=0;i<7;i++){
        cnt[team[i]]++;
        for (int j=0;j<7;j++)
            if (team[i] == team[j])
                for (int k=0;k<n;k++)
                    if (name[i] == good[k][0] && name[j] == good[k][1])
                        res.second++;
    }
    if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)
        return mp(1<<30,-(1<<30));
    res.first = max(max(a/cnt[0],b/cnt[1]),c/cnt[2])-min(min(a/cnt[0],b/cnt[1]),c/cnt[2]);
    return res;
}

pair<int,int> res;

void per(int i){
    if (i == 7){
        pair<int,int> tmp = calc();
        if (tmp.first < res.first || (tmp.second > res.second && tmp.first == res.first))
            res = tmp;
        return;         
    }
    team[i]=0;
    per(i+1);
    team[i]=1;  
    per(i+1);
    team[i]=2;
    per(i+1);
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>good[i][0];
        cin>>good[i][1];
        assert(good[i][1] == "likes");
        cin>>good[i][1];
    }
    cin>>a>>b>>c;
    res = calc();
    per(0); 
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
}