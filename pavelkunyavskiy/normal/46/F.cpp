#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include <memory.h>

#define dbg(a,n) copy(a,a+n,ostream_iterator<int>(cerr," "));cerr<<endl;


#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int64;
typedef long double ld;

pair<int,int> g[1100];
int n,m,k;

struct snm{
    int p[1100];
    bool opened[1100];
    //int posper[1100];
    int pos[1100];
    
    snm(int* kpos){
    for (int i=0;i<m;i++)
        pos[i]=kpos[i];
    solve();
    }    
    
    snm(snm* a,snm* b){
    init();
    for (int i=0;i<m;i++)
        if (a->opened[i] && b->opened[i])
        uni(g[i].first,g[i].second);
    }
    
    void init(){
    for (int i=0;i<n;i++)
        p[i]=i;
    memset(opened,false,sizeof(opened));
    }
    
    int root(int v){
    if (p[v]==v) return v;
    return p[v]=root(p[v]);
    }
    
    void uni(int a,int b){
    a=root(a);
    b=root(b);
    if (a==b) return;
    if (rand()&1)
        p[a]=b;
    else
        p[b]=a;
    }   
   
    void solve();
};

void snm::solve(){   
    //cerr<<"!!!!!!!!"<<endl;
    bool update=true;
    init();
   // dbg(pos,m);
    for (;update;){
    update=false;
    for (int i=0;i<m;i++){
        if (opened[i]) continue;
        int a=root(g[i].first);
        int b=root(g[i].second);
        int c=root(pos[i]);
        //cerr<<"TRY OPEN:" <<i<<endl;
        //cerr<<a<<" "<<b<<" "<<c<<endl;
        //cerr<<g[i].first<<" "<<g[i].second<<" "<<pos[i]<<endl;
        if (a==c || b==c){
        //cerr<<"OPEND: "<<i<<endl;
        uni(a,b);
        update=true;
        opened[i]=true;
        }
    }    
    }
}

snm *start,*finish,*middle;

int roomes[2][1100];
int keypos[2][1100];
int keyper[2][1100];
map<string,int> names;
int cnt;

int getnum(string s){
    if (names.find(s)==names.end())
    return names[s]=cnt++;
    return names[s];
}

void error(){
    printf("NO\n");
    exit(0);
}



int main(){
    scanf(" %d %d %d ",&n,&m,&k);
    for (int i=0;i<m;i++){
    scanf("%d %d",&g[i].first,&g[i].second);
    --g[i].first,--g[i].second;
    }
    for (int i=0;i<2;i++){
    for (int j=0;j<k;j++){
        string s;
        cin>>s;
        int number=getnum(s);
        scanf("%d",&roomes[i][number]);
        --roomes[i][number];
        int keys=0;
        scanf("%d",&keys);
        for (int l=0;l<keys;++l){
        int tmp;
        scanf("%d",&tmp);
        //cerr<<s<<" "<<tmp<<endl;
        --tmp;
        keypos[i][tmp]=roomes[i][number];
        keyper[i][tmp]=number;
        }
    }
    }
    //dbg(keypos[1],m);
    start=new snm(keypos[0]);
    //return 0;
    //cerr<<endl<<endl;
    finish=new snm(keypos[1]);
    //dbg(finish->opened,m);
    middle=new snm(start,finish);
    for (int i=0;i<k;i++)
    if (middle->root(roomes[0][i])!=middle->root(roomes[1][i]))
        error();
    for (int i=0;i<m;i++)
    if (middle->root(keypos[0][i])!=middle->root(keypos[1][i]))
        error();
    for (int i=0;i<m;i++)
    if (middle->root(roomes[0][keyper[0][i]])!=middle->root(roomes[1][keyper[1][i]]))
        error();
    printf("YES\n");
    return 0;  
}