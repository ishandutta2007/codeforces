#include<cstdio>
#include<algorithm>
using namespace std;
int x[3];
int main(){
	scanf("%d%d%d",&x[0],&x[1],&x[2]); sort(x,x+3);
	if(x[0]==1||x[0]==2&&x[1]==2||x[0]==3&&x[1]==3&&x[2]==3||x[0]==2&&x[1]==4&&x[2]==4) printf("YES"); else printf("NO");
}