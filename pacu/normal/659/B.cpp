#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string name[100000];
int reg[100000];
int score[100000];

vector<int> lst[10000];

bool cmp(int a,int b)
{
	return score[a]>score[b];
}

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> name[i] >> reg[i] >> score[i];
		reg[i]--;
		lst[reg[i]].push_back(i);
	}
	for(int i=0;i<M;i++)
	{
		sort(lst[i].begin(),lst[i].end(),cmp);
		if(lst[i].size() == 2 || score[lst[i][1]]!=score[lst[i][2]])
			cout << name[lst[i][0]] << ' ' << name[lst[i][1]] << '\n';
		else
			cout << "?\n";
	}
}