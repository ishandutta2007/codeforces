var
  s:ansistring;
  ans,d,i,j,l1,l2,z,k:longint;

begin
  readln(s);
  d:=length(s);
  ans:=0;
  i:=d;
  while (i<=d) do
  begin
    j:=i;
    while (1<=j) and (s[j]='0') do dec(j);
    if (j=1) then begin inc(ans); break; end;
    l1:=j-1;
    l2:=i-j+1;
    if (l1>l2) then begin inc(ans); i:=j-1; continue; end;
    if (l1<l2) then begin inc(ans); break; end;
    if (l1=l2) then
    begin
      z:=0;
      for k:=0 to l1-1 do
      begin
        if (s[1+k]>s[j+k]) then begin z:=+1; break; end;
        if (s[1+k]<s[j+k]) then begin z:=-1; break; end;
      end;
      if (z=-1) then begin inc(ans); break; end;
      inc(ans);
      i:=j-1;
    end;
  end;
  writeln(ans);
end.