#include<bits/stdc++.h>
using namespace std;
short int A[5000][3]={{0}};
int l;



int count (string str,int i,int s)
{
	if(i==l)
		return 0;
	if(A[i][s])
		return(A[i][s]);
	else
	{
		if(s==0&&str[i]=='a')
			A[i][s]=1+count(str,i+1,s);
		else if(s==0&&str[i]=='b')
			A[i][s]=max(1+count(str,i+1,s+1),count(str,i+1,s));
		else if(s==1&&str[i]=='b')
			A[i][s]=1+count(str,i+1,s);
		else if(s==1&&str[i]=='a')
			A[i][s]=max(1+count(str,i+1,s+1),count(str,i+1,s));
		else if(s==2&&str[i]=='a')
			A[i][s]=1+count(str,i+1,s);
		else if(s==2&&str[i]=='b')
			A[i][s]=count(str,i+1,s);
	}
	return(A[i][s]);
}


int main()
{
	string str;
	cin>>str;
	l=str.length();
	int l=count(str,0,0);
	cout<<l;
}