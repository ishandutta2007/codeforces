#include <cstdio>
#include <vector>
using namespace std;
#define M 262144

int tree[M*2];
void upd(int x,int v){
    x+=M; while(x) tree[x]+=v, x>>=1;
}
int rs(int a,int b){
    a+=M; b+=M;
    int ret=0;
    while(a<=b){
        if(a==b){ ret+=tree[a]; break; }
        if(a%2==1) ret+=tree[a++];
        if(b%2==0) ret+=tree[b--];
        a>>=1; b>>=1;
    }
    return ret;
}

void iniT(int n){
    for(int i=0;i<n;++i) tree[i+M]=1;
    for(int i=M-1;1<=i;--i) tree[i]=tree[i<<1]+tree[(i<<1)|1];
}

vector<int> p(vector<int> arr){
    int n=arr.size();
    iniT(n);
    vector<int> ret;
    for(int i=0;i<n;++i){
        ret.push_back(rs(0, arr[i]-1));
        upd(arr[i], -1);
    }
    return ret;
}

int kth(int k){
    int x=1;
    int cs=0;
    ++k;
    //printf("K %d\n",k);
    while(x<M){
        x<<=1;
        //printf("x %d; cs %d, tree %d\n",x,cs,tree[x]);
        if(cs+tree[x]<k){
            //puts("move right");
            cs+=tree[x]; ++x;
        }
    }
    return x-M;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a, pa, b, pb;
{
    int buf;
    for(int i=0; i<n; ++i) scanf("%d",&buf), a.push_back(buf);
    for(int i=0; i<n; ++i) scanf("%d",&buf), b.push_back(buf);
}
    pa=p(a); pb=p(b);
    vector<int> pc(n, 0);
    for(int i=n-2; 0<=i; --i){
        pc[i]+=pa[i]+pb[i];
        if(i){
            pc[i-1] += pc[i]/(n-i);
        }
        pc[i] %= (n-i);
    }
    iniT(n);
    for(int i=0; i<n; ++i){
        int t=kth(pc[i]);
        printf("%d ",t);
        upd(t, -1);
    }
    return 0;
}