#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

vector<P> out[200000];
vector<P> in[200000];
int a1[45]={1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9};
int a2[45]={0,0,1,0,1,2,0,1,2,3,0,1,2,3,4,0,1,2,3,4,5,0,1,2,3,4,5,6,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,8};

int gcd(int a,int b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}

bool comp(P a,P b) {
    if (a.second==b.second) {
        return a.first<b.first;
    }
    return a.second<b.second;
}

vector<int> v;
bool okay[10][10][10][10];
bool chk[45][45];
int fac[10];

int main(void) {
    fac[0]=1;
    for(int i=1;i<10;i++) {
        fac[i]=(fac[i-1]*i);
    }
    memset(okay,-1,sizeof(okay));
    int n,m,_k;
    scanf("%d %d %d",&n,&m,&_k);
    for(int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        u--;
        v--;
        out[u].push_back(P(v,w));
        in[v].push_back(P(u,w));
    }
    for(int i=0;i<n;i++) {
        sort(out[i].begin(),out[i].end(),comp);
    }
    for(int p=0;p<n;p++) {
        int arr[10][9];
        memset(arr,0,sizeof(arr));
        for(int j=0;j<in[p].size();j++) {
            int x=in[p][j].second;
            int nt=in[p][j].first;
            int ind;
            for(int k=0;k<out[nt].size();k++) {
                if (x==out[nt][k].second) {
                    ind=k;
                    break;
                }
            }
            arr[out[nt].size()][ind]++;
        }
        for(int i=0;i<45;i++) {
            if (arr[a1[i]][a2[i]]>1) {
                chk[i][i]=true;
            }
            if (arr[a1[i]][a2[i]]>=1) {
                for(int j=i+1;j<45;j++) {
                    if (arr[a1[j]][a2[j]]==1) {
                        chk[i][j]=true;
                        chk[j][i]=true;
                    }
                }
            }
        }
    }
    for(int i=0;i<45;i++) {
        for(int j=i;j<45;j++) {
            if (chk[i][j]) {
                int d1=a1[i];
                int d2=a1[j];
                int r1=a2[i];
                int r2=a2[j];
                okay[d1][r1][d2][r2]=false;
                okay[d2][r2][d1][r1]=false;
            }
        }
    }
    int ret=0;
    for(int x=0;x<fac[_k];x++) {
        int arr[10];
        for(int j=0;j<9;j++) {
            arr[j+1]=(x/fac[j])%(j+1);
        }
        bool flag=true;
        for(int i=1;i<=9;i++) {
            for(int j=1;j<=9;j++) {
                if (!okay[i][arr[i]][j][arr[j]]) {
                    flag=false;
                    break;
                }
            }
        }
        ret+=flag;
    }
    printf("%d",ret);
}