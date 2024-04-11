var
    a:array[1..2,1..100] of int64; limit:array[1..101] of int64;
     n,t,i,j:longint; ans,tek,mnog,ost:int64;


procedure bubblesort;
  var i,j,w:longint;
begin
  for i:=1 to n do
    for j:=i+1 to n do
      if a[2,i]>a[2,j] then
    begin
      w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
      w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
    end;
end;


begin

  readln(n);
    for i:=1 to n do readln(a[1,i],a[2,i]);
    readln(t);
  for i:=1 to t do read(limit[i]);

  bubblesort; tek:=0; ans:=0; j:=1; mnog:=1;
    limit[t+1]:=maxlongint*maxlongint;
  for i:=1 to n do
    if tek+a[1,i]>limit[j] then
      begin
        ost:=a[1,i];
        while tek+ost>limit[j] do
          begin
            ans:=ans + (limit[j]-tek)*mnog*a[2,i];
              ost:=ost-(limit[j]-tek); mnog:=j+1;
            tek:=limit[j]; inc(j);
          end;
        ans:=ans + ost*mnog*a[2,i];
        tek:=tek+ost;
      end
        else
      begin
        ans:=ans + a[1,i]*mnog*a[2,i];
        tek:=tek+a[1,i];
      end;
  writeln(ans);

end.