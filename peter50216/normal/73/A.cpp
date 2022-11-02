#include<stdio.h>
#include<algorithm>
using namespace std;
long long x,y,z,k;
inline long long solve(){
    if(k>=x+y+z-3)return x*y*z;
    else if(k>=2*y+z-3)return y*z*(k-(y+z-2)+1);
    else if(k>=3*z-3){
	long long e=z-1,w=z-1,q=z-1;
	w+=(k-3*z+3)/2;
	q+=(k-3*z+3+1)/2;
	return (q+1)*(w+1)*(e+1);
    }else{
	return (k/3+1)*((k+1)/3+1)*((k+2)/3+1);
    }
}
int main(){
    scanf("%I64d%I64d%I64d%I64d",&x,&y,&z,&k);
    if(x<y)swap(x,y);
    if(x<z)swap(x,z);
    if(y<z)swap(y,z);
    printf("%I64d\n",solve());
}