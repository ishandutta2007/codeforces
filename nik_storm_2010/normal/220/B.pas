uses math;
var
    a:array[1..3,1..100000] of longint; pred,plus,n,m,i,j:longint;
      sta,kol,tek:array[0..100000] of longint;


begin

  readln(n,m);
  for i:=1 to n do
    begin
      read(sta[i]);
      if sta[i]<=100000 then
        begin
          pred:=max(pred,sta[i]);
          inc(kol[sta[i]]);
        end;
    end; readln;
  for i:=1 to m do readln(a[1,i],a[2,i]);

  for i:=1 to pred do
    if (i<=kol[i]) then
      begin
        for j:=1 to n do
          begin
            if sta[j]=i then plus:=1 else plus:=0;
            tek[j]:=tek[j-1]+plus;
          end;
        for j:=1 to m do
          if tek[a[2,j]]-tek[a[1,j]-1]=i then inc(a[3,j]);
      end;
  for i:=1 to m do writeln(a[3,i]);

end.