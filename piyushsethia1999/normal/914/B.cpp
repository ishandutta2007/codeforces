#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,A[100001]={0},x;
	cin>>n;
//	cout<<n<<"\n";
	for(int i=0;i<n;i++){
		cin>>x;
		A[x]++;
	}
//	for(int i=0;i<10;i++)
//	    cout<<A[i]<<" ";
	//cout<<"\n";
	int count=0;
	bool b=false;
	for(int i=100001;i>=1;i--)
	{
		if(A[i]&1){
			b=true;
			break;
		}
	}
	if(b){
		cout<<"Conan";
	}
	else{
		cout<<"Agasa";
	}


}