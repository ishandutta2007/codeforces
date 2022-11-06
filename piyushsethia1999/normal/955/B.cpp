#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF 1<<30

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin>>str;
	int l= str.size();
	int count=0;
	int A[26]={0};
	for (int i = 0; i < l; ++i)
	{
		if(!A[str[i]-97]){
			count++;
		}
		A[str[i]-97]++;
	}
	if(count>4){
		cout<<"No";
	}
	else{
		if(count==3){
			if(l==3){
				cout<<"No";
			}
			else {
				cout<<"Yes";
			}
		}
		else if(count==4){
			cout<<"Yes";
		}
		else if(count==1){
			cout<<"No";
		}
		else{
			int e[2]={0};
			int h=0;
			for (int i = 0; i < 26; ++i)
			{
				if(A[i]){
					e[h]=A[i];
					h++;
				}
			}
			if(e[0]>1&&e[1]>1){
				cout<<"Yes";
			}
			else{
				cout<<"No";
			}
		}
	}
}