#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> cnt(26);
	for(int i=0;i<n;i++)
    {
        string ime;
        cin >> ime;
        cnt[ime[0]-'a']++;
    }
    int x=0;
    for(int i=0;i<26;i++)
    {
        int tren_broj=cnt[i];
        int grupa1=tren_broj/2,grupa2=tren_broj-grupa1;
        int br1=grupa1*(grupa1-1)/2,br2=grupa2*(grupa2-1)/2;
        x+=br1+br2;
    }
    printf("%i\n",x);
    return 0;
}