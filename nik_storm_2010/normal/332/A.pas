var
  ans,cur,i,j,d,n:longint; s:ansistring; p:array[1..3] of char;


begin
  readln(n); readln(s); d:=length(s);
  ans:=0; cur:=0;
  for i:=1 to d do
  begin
    if (i>=4) and (cur=0) then
    begin
      if (p[1]=p[2]) and (p[2]=p[3]) then inc(ans);
    end;
    if i>=4 then
    begin
      for j:=1 to 2 do p[j]:=p[j+1];
      p[3]:=s[i];
    end
    else p[i]:=s[i];
    cur:=(cur+1) mod n;
  end;
  writeln(ans);
end.