Var
   a: array[1..8,1..8] of longint;
    used: array[1..8] of boolean;
     b: array[1..8] of longint;
      max,min,answer,tek,k,n,i,j:longint;
       c:char;


procedure rec(nom:longint);
var i,j:longint;
 begin
  if nom = k+1
   then
    begin
     max:=0; min:=MaxLongint;
     for i:=1 to n do
      begin
       tek:=0;
        for j:=1 to k do tek:=(tek*10)+a[i,b[j]];
       if max < tek then max:=tek;
        if min > tek then min:=tek;
      end;
      if max-min < answer then answer:=max-min;
    end
   else
    begin
     for i:=1 to k do
      if used[i]=false
       then
        begin
         used[i]:=true;
          b[nom]:=i;
           rec(nom+1);
         used[i]:=false;
        end;
    end;
 end;


Begin

  readln(n,k);
   for i:=1 to n do
    begin
     for j:=1 to k do
      begin
       read(c);
        val(c,a[i,j]);
      end;
     readln;
    end;

  answer:=MaxLongint;
   rec(1);
    writeln(answer);

End.