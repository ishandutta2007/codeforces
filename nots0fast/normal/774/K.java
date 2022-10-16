
import java.lang.Math;
import java.io.*;
import java.util.*;// headers MUST be above the first class

// one class needs to have a main() method
public class HelloWorld
{
  // arguments are passed using the text field below this editor
  public static void main(String[] args)
  {
    Scanner S = new Scanner(System.in);
    int n = 0 ;String aa = "";
    if(S.hasNextInt()==true)
    n = S.nextInt();
    if(S.hasNext())
    aa = S.next();
    char[] bax = new char[n];
    for(int i=0; i<n; i=i+1)
    {
        bax[i] = '0';
    }
    int point = 0;
    for(int i=0; i<n; i=i+1)
    {
      char zaa = aa.charAt(i);
      if(zaa=='o' || zaa=='e' || zaa=='a' || zaa=='i' || zaa=='u' || zaa=='y' ) 
      {
      int init = i;
      while(i<n && aa.charAt(i)==zaa)
      {
        i=i+1;
      }
      i=i-1;
      if(i-init==1 && (zaa=='o' || zaa=='e') )
      {
        bax[point] = zaa;
        ++point;
        bax[point] = zaa;
        ++point;
      }
      else
      {
        bax[point] = zaa;
        ++point;
      }
      }
      else
      {
          bax[point] = zaa;
        ++point;
      }
    }
    int i = 0;
    while(i<n && bax[i]!='0')
    {
        System.out.print(bax[i]);
        i = i+1;
    }
  }
}