uses math;
var
    a:array[1..2,1..100000] of longint; answer,pred,n,m,i,j:longint;


procedure quicksort(nom,l,r:longint);
var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=a[nom,random(r-l+1)+l];
  while i<=j do
    begin
      while a[nom,i]<d do inc(i);
      while a[nom,j]>d do dec(j);
      if i<=j then
        begin
          w:=a[nom,i]; a[nom,i]:=a[nom,j]; a[nom,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(nom,i,r);
  if l<j then quicksort(nom,l,j);
end;


begin

  readln(m); for i:=1 to m do read(a[1,i]); readln;
  readln(n); for i:=1 to n do read(a[2,i]); readln;
  randomize; quicksort(1,1,m); quicksort(2,1,n);
  answer:=0; i:=n;
  while i<>0 do
    begin
      if i>a[1,1] then
        begin
          pred:=max(1,i-(a[1,1]+1));
          for j:=i downto pred do answer:=answer+a[2,j];
          if i>=a[1,1]+2 then
            begin
              answer:=answer-a[2,pred]-a[2,pred+1];
            end
              else
            begin
              answer:=answer-a[2,pred];
            end;
          i:=pred-1;
        end
          else
        begin
          for j:=i downto 1 do answer:=answer+a[2,j];
          i:=0;
        end;
    end;
  writeln(answer);

end.