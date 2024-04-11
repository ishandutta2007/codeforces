#include<iostream>
#include<string.h>

using namespace std;

int n,m;
int a[15][5],b[15][5];
bool can[10];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2];
	for(int i=1;i<=m;i++)
		cin>>b[i][1]>>b[i][2];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((a[i][1]==b[j][1]&&a[i][2]==b[j][2])||(a[i][1]==b[j][2]&&a[i][2]==b[j][1]))
				continue;
			if(a[i][1]!=b[j][1]&&a[i][1]!=b[j][2]&&a[i][2]!=b[j][1]&&a[i][2]!=b[j][2])
				continue;
			if(a[i][1]==b[j][1]||a[i][1]==b[j][2])
				can[a[i][1]]=true;
			if(a[i][2]==b[j][1]||a[i][2]==b[j][2])
				can[a[i][2]]=true;
		}
	}
	int cnt=0;
	for(int i=1;i<=9;i++)
		if(can[i])
			cnt++;
	if(cnt==1){
		for(int i=1;i<=9;i++){
			if(can[i]){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		memset(can,false,sizeof(can));
		for(int j=1;j<=m;j++){
			if((a[i][1]==b[j][1]&&a[i][2]==b[j][2])||(a[i][1]==b[j][2]&&a[i][2]==b[j][1]))
				continue;
			if(a[i][1]!=b[j][1]&&a[i][1]!=b[j][2]&&a[i][2]!=b[j][1]&&a[i][2]!=b[j][2])
				continue;
			if(a[i][1]==b[j][1]||a[i][1]==b[j][2])
				can[a[i][1]]=true;
			if(a[i][2]==b[j][1]||a[i][2]==b[j][2])
				can[a[i][2]]=true;
		}
		cnt=0;
		for(int i=1;i<=9;i++)
			if(can[i])
				cnt++;
		if(cnt>1){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int j=1;j<=m;j++){
		memset(can,false,sizeof(can));
		for(int i=1;i<=n;i++){
			if((a[i][1]==b[j][1]&&a[i][2]==b[j][2])||(a[i][1]==b[j][2]&&a[i][2]==b[j][1]))
				continue;
			if(a[i][1]!=b[j][1]&&a[i][1]!=b[j][2]&&a[i][2]!=b[j][1]&&a[i][2]!=b[j][2])
				continue;
			if(a[i][1]==b[j][1]||a[i][1]==b[j][2])
				can[a[i][1]]=true;
			if(a[i][2]==b[j][1]||a[i][2]==b[j][2])
				can[a[i][2]]=true;
		}
		cnt=0;
		for(int i=1;i<=9;i++)
			if(can[i])
				cnt++;
		if(cnt>1){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}