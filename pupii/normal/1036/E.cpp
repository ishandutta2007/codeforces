// It is made by XZZ
#include<bits/stdc++.h>
#define il inline
#define rg register
#define vd void
#define sta static
#define double long double
typedef long long ll;
using namespace std;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int A[1010],B[1010],C[1010],D[1010];
std::map<std::pair<int,int>,int>M;
std::map<int,int>F;
double k[1010],b[1010];
bool y[1010];
il bool in(int a,int b,int c){
    if(b>c)std::swap(b,c);
    return b<=a&&a<=c;
}
main(){
    int n=gi(),ans=0;
    for(int i=1;i<=n;++i)A[i]=gi(),B[i]=gi(),C[i]=gi(),D[i]=gi(),ans+=__gcd(llabs(C[i]-A[i]),llabs(D[i]-B[i]))+1;
    for(int i=1;i<=n;++i)
        if(A[i]!=C[i]){
            k[i]=1.0*(D[i]-B[i])/(C[i]-A[i]);
            b[i]=B[i]-k[i]*A[i];
        }else y[i]=1;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j){
            if(y[i]||y[j]){
                if(!(y[i]&&y[j])){
                    double x=y[i]?A[i]:A[j];
                    double yy=y[i]?(k[j]*x+b[j]):(k[i]*x+b[i]);
                    int X=(int)round(x);
                    int Y=(int)round(yy);
                    if(!in(X,A[i],C[i])||!in(X,A[j],C[j])||!in(Y,B[i],D[i])||!in(Y,B[j],D[j]))continue;
                    if(fabs(x-X)>1e-7||fabs(yy-Y)>1e-7)continue;
                    ++M[std::make_pair(X,Y)];
                }
            }
            else if(fabs(k[i]-k[j])>1e-10){
                double x=(b[i]-b[j])/(k[j]-k[i]);
                double y=k[i]*x+b[i];
                int X=(int)round(x);
                int Y=(int)round(y);
                if(!in(X,A[i],C[i])||!in(X,A[j],C[j])||!in(Y,B[i],D[i])||!in(Y,B[j],D[j]))continue;
                if(fabs(x-X)>1e-7||fabs(y-Y)>1e-7)continue;
                ++M[std::make_pair(X,Y)];
            }
        }
    for(int i=1;i<=n;++i)F[i*(i-1)/2]=i-1;
    for(std::map<std::pair<int,int>,int>::iterator i=M.begin();i!=M.end();++i)ans-=F[i->second];
    printf("%d\n",ans);
    return 0;
}