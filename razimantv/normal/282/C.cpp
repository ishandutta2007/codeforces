# include <cstdio>
# include <cstring>

using namespace std;

char A[1000001],B[1000001];

int main()
{
	scanf("%s%s",A,B);

	if(strlen(A)!=strlen(B))
	{
		printf("NO\n");
		return 0;
	}

	int cnt1=0,cnt2=0;
	for(int i=0;A[i];i++)
	{
		if(A[i]=='1')cnt1++;
		if(B[i]=='1')cnt2++;
	}

	if((cnt1==0&&cnt2!=0)||(cnt1!=0&&cnt2==0))printf("NO\n");
	else printf("YES\n");

	return 0;
}