#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int N,M;
string line[5000];
int tp[5000];	//0 constant, 1 AND, 2 OR, 3 XOR
string carg[5000];
int arg1[5000];
int arg2[5000];
map<string,int> mp;
int val[5000];
char tmp1[30];
char tmp2[3000];
char tmp3[30];
char tmp4[30];
char inp[3000];

void parseLine(int i)
{
	copy(line[i].begin(),line[i].end(),inp);
	inp[line[i].size()] = '\0';
	int spaces = 0;
	for(int j=0;j<line[i].size();j++)
		if(line[i][j]==' ')
			spaces++;
	if(spaces==2)
	{
		tp[i] = 0;
		sscanf(inp,"%s := %s",tmp1,tmp2);
		mp[tmp1] = i;
		carg[i].assign(tmp2,strlen(tmp2));
	}
	else
	{
		string op;
		sscanf(inp,"%s := %s %s %s",tmp1,tmp2,tmp3,tmp4);
		mp[tmp1] = i;
		arg1[i] = mp[tmp2];
		op.assign(tmp3,strlen(tmp3));
		arg2[i] = mp[tmp4];
		if(op[0]=='A') tp[i] = 1;
		else if(op[0]=='O') tp[i] = 2;
		else tp[i] = 3;
	}
}

int getScore(int bIndex,int bVal)
{
	mp.clear();
	int sm = 0;
	for(int i=0;i<N;i++)
	{
		if(tp[i]==0) val[i] = carg[i][bIndex]-'0';
		else
		{
			int b1,b2;
			if(arg1[i]==-1) b1 = bVal;
			else b1 = val[arg1[i]];
			if(arg2[i]==-1) b2 = bVal;
			else b2 = val[arg2[i]];
			if(tp[i]==1) val[i] = (b1&&b2);
			else if(tp[i]==2) val[i] = (b1||b2);
			else val[i] = (b1^b2);
		}
		sm += val[i];
	}
	return sm;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	cin.ignore();
	for(int i=0;i<N;i++)
	{
		getline(cin,line[i]);
	}
	mp["?"] = -1;
	for(int i=0;i<N;i++)
	{
		parseLine(i);
	}
	string sMin,sMax;
	for(int j=0;j<M;j++)
	{
		int sm0 = getScore(j,0);
		int sm1 = getScore(j,1);
		if(sm0 < sm1) sMin += '0', sMax += '1';
		else if(sm0 > sm1) sMin += '1', sMax += '0';
		else sMin += '0', sMax += '0';
	}
	cout << sMin << '\n';
	cout << sMax << '\n';
}