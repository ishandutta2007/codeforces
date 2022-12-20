#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > occ;

int binSearch(int low,int high,int c,int x)	//occ[c], first after x
{
	if(low==high)
		return low;
	if((low+1)==high)
	{
		if(occ[c][low]>x) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(occ[c][mid]>x)
		return binSearch(low,mid,c,x);
	else
		return binSearch(mid+1,high,c,x);
}

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	for(int i=0;i<26;i++)
		occ.push_back(vector<int>());
	for(int i=0;i<s1.size();i++)
		occ[s1[i]-'a'].push_back(i);
	int cnt = 1;
	int last = -1;
	for(int i=0;i<s2.size();i++)
	{
		int ch = s2[i]-'a';
		int high = occ[ch].size()-1;
		if(high==-1)
		{
			cout << -1 << endl;
			return 0;
		}
		if(occ[ch][high]<=last)
		{
			cnt++;
			last = occ[ch][0];
		}
		else
			last = occ[ch][binSearch(0,occ[ch].size()-1,ch,last)];
	}
	cout << cnt << endl;
}