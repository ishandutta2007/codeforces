# include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int N;
	fin>>N;

	for(int i=0;i<N;i++)
	{
		int a;
		fin>>a;
		fout<<1-(a&1)<<endl;;
	}
	return 0;
}