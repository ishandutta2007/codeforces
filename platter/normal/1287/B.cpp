#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct s {
	char str[31];
};

int n;
s arr[1500];

bool comp(s a,s b) {
	int val=strcmp(a.str,b.str);
	return val<0;
}

bool search(s a) {
	int lo=0;
	int hi=n-1;
	int mid=(lo+hi)/2;
	while (lo<=hi) {
		mid=(lo+hi)/2;
		if (strcmp(a.str,arr[mid].str)==0)
		return true;
		if (strcmp(a.str,arr[mid].str)<0) {
			hi=mid-1;
		}
		else {
			lo=mid+1;
		}
	}
	return false;
}

int main() {
	int k;
	scanf("%d %d\n",&n,&k);
	s hubo[2000000];
	int hubon=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<k;j++) {
			char x;
			scanf("%c",&x);
			arr[i].str[j]=x;
		}
		scanf("\n");
	}
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			for(int p=0;p<k;p++) {
				if (arr[i].str[p]==arr[j].str[p]) {
					hubo[hubon].str[p]=arr[i].str[p];
				}
				else {
					int a=arr[i].str[p];
					int b=arr[j].str[p];
					char ret;
					if (a+b==153) {
						ret='S';
					}
					if (a+b==167) {
						ret='E';
					}
					if (a+b==152) {
						ret='T';
					}
					hubo[hubon].str[p]=ret;
				}
			}
			hubon++;
		}
	}
	sort(arr,arr+n,comp);
	long long ret=0;
	for(int i=0;i<hubon;i++) {
		if (search(hubo[i])) {
			ret++;
		}
	}
	printf("%lld",ret/3);
	return 0;
}