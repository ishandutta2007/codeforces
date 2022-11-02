#include<stdio.h>
#include<set>
using namespace std;
int nim[100100];

int main(){
    nim[1]=nim[2]=0;
    int i,j,k;
    int n;
    scanf("%d",&n);
    for(i=3;i<=n;i++){
	set<int> go;
	for(j=2;i>=j*(j+1)/2;j++){
	    if((2*i)%j==0){
		int c=0;
		int h=(2*i)/j;
		if((h-j+1)%2)continue;
		int a=(h-j+1)/2;
		int b=h-a;
		if(a>0&&b>a){
		    for(k=a;k<=b;k++)c^=nim[k];
		    go.insert(c);
		}
	    }
	}
	set<int>::iterator it;
	int c=0;
	for(it=go.begin();it!=go.end();it++){
	    if(*it!=c)break;
	    c++;
	}
	nim[i]=c;
    }
    i=n;
    if(nim[i]==0)puts("-1");
    else{
	for(j=2;i>=j*(j+1)/2;j++){
	    if((2*i)%j==0){
		int c=0;
		int h=(2*i)/j;
		if((h-j+1)%2)continue;
		int a=(h-j+1)/2;
		int b=h-a;
		if(a>0&&b>a){
		    for(k=a;k<=b;k++)c^=nim[k];
		    if(c==0)break;
		}
	    }
	}
	printf("%d\n",j);
    }
}