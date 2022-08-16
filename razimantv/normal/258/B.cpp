# include <cstdio>
# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
# include <string>
# include <cstring>

using namespace std;

long long fact[]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
long long factinv[]={1,1,500000004,166666668,41666667,808333339,301388891,900198419,487524805,831947206,283194722};
const long long MOD=1000000007;
int nongood[]={0,1,2,3,4,4,5,6,6,7},good[]={0,0,0,0,0,1,1,1,2,2};

int pow(int a,int b)
{
	if(b==0)return 1;
	long long ret=pow(a,b-1);
	ret=(ret*a)%MOD;
	return (int)ret;
}

int cntways(int dig,int fs)
{
	if(fs>dig||fs<0)return 0;
	long long ret=pow(2,fs);
	ret=(ret*pow(8,dig-fs))%MOD;
	ret=(ret*fact[dig])%MOD;
	ret=(ret*factinv[fs])%MOD;
	ret=(ret*factinv[dig-fs])%MOD;
	return ret;
}

int choose(int a,int b)
{
	long long ret=1;
	for(int i=0;i<b;i++)ret=(ret*(a-i))%MOD;
	//ret=(ret*factinv[b])%MOD;
	return (int)ret;
}

int cnt[10];

int main()
{
	char inp[11];
	cin>>inp;

	int D=strlen(inp);
	for(int i=0;i<10;i++)
	{
		int rm=0;
		for(int j=0;j<D;j++)
		{
			int d=inp[j]-'0';
			cnt[i]=(cnt[i]+nongood[d]*(long long)cntways(D-j-1,i-rm)+good[d]*(long long)cntways(D-j-1,i-rm-1))%MOD;
			if(d==4||d==7)rm++;
			if(rm>i)break;
		}
	}

	int cur=0;
	for(int i=0;i<D;i++)
		if(inp[i]=='4'||inp[i]=='7')cur++;
	cnt[cur]++;cnt[0]--;

	int DD=0;
	for(int i=0;i<10;i++)
		if(cnt[i])DD=i;
	DD++;

	int vatt[7],vatt2[10],ret=0;
	for(vatt[0]=0;vatt[0]<DD;vatt[0]++)
		for(vatt[1]=0;vatt[1]<DD;vatt[1]++)
			for(vatt[2]=0;vatt[2]<DD;vatt[2]++)
				for(vatt[3]=0;vatt[3]<DD;vatt[3]++)
					for(vatt[4]=0;vatt[4]<DD;vatt[4]++)
						for(vatt[5]=0;vatt[5]<DD;vatt[5]++)
							for(vatt[6]=0;vatt[6]<DD;vatt[6]++)
							{
								int othtot=vatt[0]+vatt[1]+vatt[2]+vatt[3]+vatt[4]+vatt[5];
								if(othtot>=vatt[6])continue;

								memset(vatt2,0,40);
								for(int i=0;i<7;i++)
									vatt2[vatt[i]]++;

								long long thisret=1;
								for(int i=0;i<10;i++)
								{
									thisret=(thisret*choose(cnt[i],vatt2[i]))%MOD;
								}

								ret=(ret+thisret)%MOD;
							}
	cout<<ret<<endl;
	return 0;
}