#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSuffix(string word,string suf)
{
	if(suf.size()>word.size())
		return 0;
	int i,j;
	for(i=(word.size()-1),j=(suf.size()-1);j>=0;j--,i--)
	{
		if(suf[j]!=word[i])
			return 0;
	}
	return 1;
}

bool isAdj(string word)
{
	return isSuffix(word,"lios")||isSuffix(word,"liala");
}
bool isNoun(string word)
{
	return isSuffix(word,"etr")||isSuffix(word,"etra");
}
bool isVerb(string word)
{
	return isSuffix(word,"initis")||isSuffix(word,"inites");
}

bool isWord(string word)
{
	return isAdj(word)||isNoun(word)||isVerb(word);
}

bool isMasc(string word)
{
	return isSuffix(word,"liala")||isSuffix(word,"etra")||
		isSuffix(word,"inites");
}

bool isFem(string word)
{
	return !isMasc(word);
}

bool isDif(string a,string b)
{
	return (isMasc(a)^isMasc(b));
}

int main()
{
	vector<string> A;
	string s;
	while(cin >> s)
		A.push_back(s);
	int N = A.size();
	int i,j;
	for(i=0;i<N;i++)
		if(!isWord(A[i]))
		{
			cout << "NO" << endl;
			return 0;
		}
	if(N==1)
	{
		cout << "YES" << endl;
		return 0;
	}
	for(i=1;i<N;i++)
		if(isDif(A[0],A[i]))
		{
			cout << "NO" << endl;
			return 0;
		}
	int nounCount = 0;
	for(i=0;i<N;i++)
		nounCount += isNoun(A[i]);
	if(nounCount!=1)
	{
		cout << "NO" << endl;
		return 0;
	}
	for(i=0;!isNoun(A[i]);i++);
	for(j=0;j<i;j++)
		if(!isAdj(A[j]))
		{
			cout << "NO" << endl;
			return 0;
		}
	for(j=(i+1);j<N;j++)
		if(!isVerb(A[j]))
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
}