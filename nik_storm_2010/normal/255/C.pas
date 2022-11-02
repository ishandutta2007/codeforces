uses math; const nn=4000;
var
  a:array[1..nn] of longint; b:array[1..2,1..nn] of longint;
  used:array[1..nn] of boolean; ans,it,n,k,i,j:longint;


begin
  readln(n); for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    if (used[i]) then continue;
    inc(k);
    for j:=i+1 to n do
      if (a[i]=a[j]) and (not used[j]) then begin used[j]:=true; a[j]:=k; end;
    a[i]:=k;
  end;
  for i:=1 to n do
  begin
    fillchar(b,sizeof(b),0); it:=0;
    for j:=i to n do
    begin
      if (a[i]=a[j]) then
      begin
        inc(it);
        inc(b[1,a[j]]); b[2,a[j]]:=it;
      end
        else
      begin
        if (b[2,a[j]]<>it) then inc(b[1,a[j]]);
        b[2,a[j]]:=it;
      end;
    end;
    for j:=1 to n do
    begin
      if (a[i]=a[j]) then ans:=max(ans,b[1,a[i]]) else
      begin
        if (b[2,a[i]]>b[2,a[j]]) then ans:=max(ans,b[1,a[j]]*2+1) else ans:=max(ans,b[1,a[j]]*2);
      end;
    end;
  end;
  writeln(ans);
end.