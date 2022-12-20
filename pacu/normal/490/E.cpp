#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ans;

int bad(string &a,string &b)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i] < b[i])
			return i;
		if(a[i] > b[i])
			return i-(1<<25);
	}
	return a.size()-1;
}

int main()
{
	int N;
	string prev = "0";
	cin >> N;
	string cur;
	string tmp;
	for(int i=0;i<N;i++)
	{
		cin >> cur;
		tmp.clear();
		if(cur.size() < prev.size())
		{
			cout << "NO" << endl;
			return 0;
		}
		else if(cur.size() > prev.size())
		{
			for(int i=0;i<cur.size();i++)
			{
				if(cur[i]!='?')
					continue;
				if(i>0)
					cur[i] = '0';
				else
					cur[i] = '1';
			}
			ans.push_back(cur);
			prev = cur;
		}
		else
		{
			for(int i=0;i<cur.size();i++)
			{
				if(cur[i]=='?')
				{
					if((i==0)&&(prev[i]=='0'))
						tmp.push_back('1');
					else
						tmp.push_back(prev[i]);
				}
				else
					tmp.push_back(cur[i]);
			}
			int k = bad(tmp,prev);
			if(k>=0)
			{
				int first = k;
				int carry = 1;
				for(int i=(cur.size()-1);i>k;i--)
					if(cur[i]=='?')
					{
						if(i==0)
							tmp[i] = '1';
						else
							tmp[i] = '0';
					}
				for(;first>=0;first--)
				{
					if(cur[first] != '?')
						continue;
					if(prev[first] == '9')
					{
						tmp[first] = '0';
						continue;
					}
					tmp[first] = prev[first]+1;
					carry = 0;
					break;
				}
				if(carry)
				{
					cout << "NO" << endl;
					return 0;
				}
			}
			if(k<0)
			{
				for(int i=(cur.size()-1);i>(k+(1<<25));i--)
					if(cur[i]=='?')
					{
						if(i==0)
							tmp[i] = '1';
						else
							tmp[i] = '0';
					}
			}
			ans.push_back(tmp);
			prev = tmp;
		}
	}
	cout << "YES" << endl;
	for(int i=0;i<N;i++)
		cout << ans[i] << endl;
	return 0;
}