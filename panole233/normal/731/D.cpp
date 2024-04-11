#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 5000000

using namespace std;

int read()
{
	int pjy=0; char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch>='0'&&ch<='9') pjy=pjy*10+ch-48,ch=getchar();
	return pjy;
}

struct W{
    int l,r;
    bool operator <(const W &a)const{
        return l<a.l;
    }
}Q[M<<1];
int a[2][M];
int main(){
    int n,c;scanf("%d %d",&n,&c);
    int cu=0,nx=1,sz=0;
    for(int i=1;i<=n;i++){
        a[cu][0]=read();
        for(int j=1;j<=a[cu][0];j++)a[cu][j]=read();
        if(i>1){
            int len=min(a[cu][0],a[nx][0]);
            bool f=false;
            for(int j=1;j<=len;j++)
                if(a[cu][j]!=a[nx][j]){
                    f=true;
                    if(a[cu][j]>a[nx][j]){
                        Q[sz++]=(W){c+1-a[cu][j],c-a[nx][j]};
                    }else if(a[cu][j]<a[nx][j]){
                        Q[sz++]=(W){0,c-a[nx][j]};
                        Q[sz++]=(W){c+1-a[cu][j],c+1};
                    }
                    break;
                }
            if(!f&&a[cu][0]<a[nx][0]){
                puts("-1");
                return 0;
            }
        }
        cu=!cu,nx=!nx;
    }
    sort(Q,Q+sz);
    int res=0;
    for(int i=0;i<sz;i++){
        if(Q[i].l>res){
            printf("%d\n",res);
            return 0;
        }else {
            if(Q[i].r+1>res)res=Q[i].r+1;
            if(Q[i].l+1>res)res=Q[i].l+1;
        }
    }
    if(res<=c)printf("%d\n",res);
    else puts("-1");
    return 0;
}