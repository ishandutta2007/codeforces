#include <stdio.h>
#include <algorithm>
#define A first
#define B second

using namespace std;

pair<int,int> tmp[100010];
int last[100010];
int arr[100010];
int n,m,l;

int main() {
	int a,b,p,val;
	int i,j,t;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
		last[i] = 0;
	}
	l = 0;
	for(i=1;i<=m;i++) {
		scanf("%d",&t);
		if(t == 1) {
			scanf("%d %d",&a,&b);
			arr[a] = b;
			last[a] = i;
		}else if(t == 2) {
			scanf("%d",&val);
			tmp[l].A = tmp[l-1].A + val;
			tmp[l].B = i;
			l++;
		}else {
			scanf("%d",&val);
			a = 0; b = l-1;
			if(last[val] <= tmp[l-1].B) {
				while(a < b) {	
					p = (a+b)/2;
					if(tmp[p].B < last[val])
						a = p+1;
					else
						b = p;
				}
				printf("%d\n",arr[val] + tmp[l-1].A - tmp[b-1].A);
			}else {
				printf("%d\n",arr[val]);
			}
		}
	}
	return 0;
}