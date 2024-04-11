#include<bits/stdc++.h>
#define maxn 3000
#define maxl 5000000
using namespace std;
struct flow {
    int v;
    int iv;
    int ca;
    int co;
};
vector<flow> a[maxn];
void add_flow(int u,int v,int ca,int co) {
    //cout<<u<<" "<<v<<" "<<co<<endl;
    a[u].push_back({v,a[v].size(),ca,co});
    a[v].push_back({u,a[u].size()-1,0,-co});
}
int iq[maxn];
long long lvl[maxn];
int pu[maxn];
int pi[maxn];
int s,t;
int q[maxl];
int d,n;

void print_fl() {
    for(int i=0;i<=t;i++) {
        for(auto v:a[i]) {
            printf("%d %d %d\n",i,v.v,v.ca);
        }
    }
}
void bf() {
    for(int i=0;i<=t;i++) {
        lvl[i]=1e18;
        iq[i]=false;
    }
    lvl[0]=0;
    q[0]=0;
    int id=0;
    iq[0]=true;
    int qlen=1;
    while(id<qlen) {
        int u=q[id];
        //cout<<u<<endl;
        iq[u]=false;
        for(int i=0;i<a[u].size();i++) {
            flow eg=a[u][i];
            int v=eg.v;
            int c=eg.co;
            if(eg.ca>0 && lvl[v]>lvl[u]+c) {
                lvl[v]=lvl[u]+c;
                pu[v]=u;
                pi[v]=i;
                //cout<<v<<" "<<i<<" "<<lvl[v]<<" "<<lvl[u]<<endl;
                if(!iq[v]) {
                    q[qlen++]=v;
                    iq[v]=true;
                }
            }
        }
        id++;
    }
}
void fl() {
    bf();
    while(lvl[t]<0) {
        int v=t;
        //print_fl();
        while(v!=s) {
            int u=pu[v];
            int i=pi[v];
            int j=a[u][i].iv;
            a[u][i].ca-=1;
            a[v][j].ca+=1;
            /*cout<<u<<" "<<v<<endl;
            cout<<a[u][i].ca<<" "<<a[v][j].ca<<endl;*/
            v=u;
            //cout<<u<<endl;
        }
        //print_fl();
        bf();
    }
    //print_fl();
}
vector<char> oper;
void add_oper(int x,int y) {
    //cout<<x<<" "<<y<<endl;
    for(int i=0;i<d;i++) {
        if((y&(1<<i))==(1<<i) && (x&(1<<i))==0) {
            oper.push_back('0'+i);
        }
    }
}
bool find_flow(int u) {
    //cout<<u<<endl;
    //cout<<u<<" "<<t<<endl;
    if(u==t) return true;
    if(u==s) {
        //cout<<"t"<<endl;
        for(int i=0;i<a[u].size();i++) {
            flow eg=a[u][i];
            int v=eg.v;
            if(eg.ca==0 && v%2==1) {
                int j=a[u][i].iv;
                a[u][i].ca=1;
                a[v][j].ca=0;
                int c=(v+1)/2;
                add_oper(0,c);
                return find_flow(v);
            }
        }
        //cout<<"c"<<endl;
        return false;
    }
    else {
        if(u%2==1) {
            for(int i=0;i<a[u].size();i++) {
                int v=a[u][i].v;
                if(v==u+1 && a[u][i].ca==0) {
                    int j=a[u][i].iv;
                    a[u][i].ca=1;
                    a[v][j].ca=0;
                    //cout<<u<<" "<<v<<" "<<j<<" "<<a[v][j].ca<<endl;
                    return find_flow(v);
                }
            }
            return false;
        }
        else {
            for(int i=0;i<a[u].size();i++) {
                int v=a[u][i].v;
                //cout<<u<<" "<<v<<" "<<a[u][i].ca<<endl;
                if(a[u][i].ca==0 && v!=u-1) {
                    int j=a[u][i].iv;
                    a[u][i].ca=1;
                    a[v][j].ca=0;
                    //cout<<u<<" "<<v<<" "<<i<<" "<<a[u][i].ca<<endl;
                    if(v==t) {
                        oper.push_back('R');
                        return find_flow(t);
                    }
                    else {
                        int c=(v+1)/2;
                        add_oper(u/2,c);
                        return find_flow(v);
                    }
                }
            }
            return false;
        }
    }
}
vector<int> num;
char st[20];
int main() {
    scanf("%d %d",&d,&n);
    t=(1<<d)*2+5;
    for(int i=0;i<n;i++) {
        scanf("%s",st);
        int x=0;
        for(int j=0;j<d;j++) {
            if(st[j]=='1') {
                x|=(1<<j);
            }
        }
        num.push_back(x);
    }
    for(int i=0;i<num.size();i++) {
        add_flow(s,num[i]*2-1,1,__builtin_popcount(num[i]));
        add_flow(num[i]*2-1,num[i]*2,1,-10000);
        add_flow(num[i]*2,t,1,1);
    }
    for(int i=0;i<num.size();i++) {
        for(int j=0;j<num.size();j++) {
            if(i==j || (num[i]&num[j])!=num[i]) continue;
            add_flow(num[i]*2,num[j]*2-1,1,__builtin_popcount(num[i]^num[j]));
        }
    }
    //print_fl();
    fl();
    //printf("ok\n");
    int iter=0;
    //print_fl();
    while(find_flow(0)) {
        iter++;
    }
    oper.pop_back();
    printf("%d\n",oper.size());
    for(auto ch:oper) {
        printf("%c ",ch);
    }
    return 0;
}