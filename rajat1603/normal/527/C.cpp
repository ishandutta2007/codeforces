#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    return x;
}
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define author rajat1603
#define N 200002
#define inf 2147483646
#define ppi pair < int, pair<int , int> >
#define add insert
set< ppi > horizontal,vertical;
set<int> hcut,vcut;
int main(){
    int w=scan(),h=scan(),n=scan();
    hcut.add(0);
    vcut.add(0);
    hcut.add(h);
    vcut.add(w);
    horizontal.insert(mp(h,mp(0,h)));
    vertical.insert(mp(w,mp(0,w)));
    for(int i=0;i<n;++i){
        char type;
        int x;
        cin>>type;
        x=scan();
        if(type=='V'){
            vcut.add(x);
            set<int>::iterator it=vcut.lower_bound(x);
            set<int>::iterator it2=it;
            it++;it2--;
            vertical.erase(mp( (*it) - (*it2),mp(*it2,*it) ) ) ;
            vertical.insert(mp( (*it) - x ,mp(x,*it) )) ;
            vertical.insert( mp( x-(*it2),mp(*it2,x)  ) )   ;
        }
        else{
            hcut.add(x);
            set<int>::iterator it=hcut.lower_bound(x);
            set<int>::iterator it2=it;
            it++;it2--;
            horizontal.erase(mp((*it)-(*it2),mp(*it2,*it))) ;
            horizontal.add(mp((*it) - x ,mp(x,*it))) ;
            horizontal.add(mp(x-(*it2),mp(*it2,x)))   ;
        }
        long long hori = horizontal.rbegin()->first;
        long long verti = vertical.rbegin()->first;
        printf("%I64d\n",hori*verti);
    }
}