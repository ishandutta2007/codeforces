uses math;
 var
    a:array[1..100000] of int64; n,i:longint;
     ans,pred:int64;


begin

  readln(n);
   for i:=1 to n do read(a[i]);
  ans:=0; pred:=0;

  for i:=2 to n do
   if a[i]<a[i-1]
    then
     begin
      ans:=ans + max(a[i-1]-a[i]-pred,0);
       pred:=a[i-1]-a[i];
      a[i]:=a[i-1];
     end
    else pred:=0;
  writeln(ans);

end.