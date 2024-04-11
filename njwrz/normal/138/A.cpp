#include <bits/stdc++.h>
using namespace std;
int ff[5];
int k;
bool str[50];
string s[4]={"","aabb","abab","abba"};
void voi(){
	string a[5];int i,j,l[5];
	for(i=1;i<=4;i++)cin>>a[i];
	int f=0,re;
	for(j=1;j<=4;j++){
		f=0;
		for(i=a[j].size()-1;i>=0;i--){
			if(str[(int)(a[j][i])]){
				f++;
			}
			if(f==k)break;
		}
		if(f!=k){
			ff[0]=1;return ;
		}
		l[j]=a[j].size()-i;
	}
	string t1,t2,t3,t4;
	t1=a[1].substr(a[1].size()-l[1]);
	t2=a[2].substr(a[2].size()-l[2]);
	t3=a[3].substr(a[3].size()-l[3]);
	t4=a[4].substr(a[4].size()-l[4]);
	if(t1==t2&&t1==t3&&t1==t4){
		return ;
	}else if(t1==t2&&t3==t4){
		ff[1]=1;return;
	}else if(t1==t3&&t2==t4){
		ff[2]=1;return ;
	}else if(t1==t4&&t2==t3){
		ff[3]=1;return ;
	}else{
		ff[0]=1;return ;
	}
}
int main(){
	int n;
	cin>>n>>k;
	str[(int)('a')]=1;
	str[(int)('e')]=1;
	str[(int)('i')]=1;
	str[(int)('o')]=1;
	str[(int)('u')]=1;
	for(int i=0;i<n;i++)voi();
	if(ff[0]){
		cout<<"NO";return 0;
	}
	int ans=0,t=0;
	for(int i=1;i<4;i++){
		if(ff[i]){
			t++;ans=i;
		}
	}
	if(t==0){
		cout<<"aaaa";return 0;
	}
	if(t>1){
		cout<<"NO";return 0;
	}
	cout<<s[ans];
	return 0;
}