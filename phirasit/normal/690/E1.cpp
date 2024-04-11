#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int arr[610][610]={};
int main()
{
	int T,w,h;
	double avg;
	scanf("%d",&T);
	for(int z=1;z<=T;z++){
		scanf("%d %d",&h,&w);
		avg=0;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				scanf("%d",&arr[i][j]);
			}
		}
		for(int i=1;i<=w;i++){
			avg+=abs(arr[h/2][i]-arr[h/2+1][i]);
		}
		avg/=(double)(w);
		if(avg>=45)printf("YES\n");
		else printf("NO\n");
	}
}