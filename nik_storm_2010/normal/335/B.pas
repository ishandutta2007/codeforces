uses math;
type point=record prev,ss:longint; end;
const ogr=50000; lim=50;
var
  f:array[0..ogr,0..lim] of point; m:array[0..ogr,'a'..'z'] of longint;
  ll:array['a'..'z'] of longint; maybe,nn,num,ret:array[0..lim] of longint;
  big:array[0..ogr] of point; s:ansistring; ans,n,i,j,nom:longint; c:char;


procedure outp(i,leng:longint;aa:string);
var lll:longint;
begin
  lll:=i;
  while (lll<>0) do
  begin
    aa:=s[lll]+aa+s[lll];
    lll:=f[lll,leng].prev;
    dec(leng);
  end;
  writeln(aa);
  halt;
end;


begin
  readln(s); n:=length(s); ans:=0;
  for i:=1 to n do
  begin
    ll[s[i]]:=i;
    for c:='a' to 'z' do m[i,c]:=ll[c];
  end;
  for i:=1 to n do
  begin
    fillchar(nn,sizeof(nn),0);
    for j:=lim downto 1 do
    begin
      if (maybe[j]<>0) and (maybe[j]>i) and (j*2+1>big[i].ss) then begin big[i].prev:=num[j]; big[i].ss:=j*2+1; end;
      if (j=1) then
      begin
        if (m[n,s[i]]<>i) then
        begin
          f[i,j].prev:=0; f[i,j].ss:=m[n,s[i]];
          if (m[n,s[i]]>maybe[j]) then num[j]:=i;
          nn[1]:=max(maybe[j],m[n,s[i]]);
        end;
      end
        else
      begin
        if (maybe[j-1]<>0) and (maybe[j-1]>i) and (m[maybe[j-1]-1,s[i]]>i) then
        begin
          f[i,j].prev:=num[j-1]; f[i,j].ss:=m[maybe[j-1]-1,s[i]];
          if (m[maybe[j-1]-1,s[i]]>maybe[j]) then num[j]:=i;
          nn[j]:=max(maybe[j],m[maybe[j-1]-1,s[i]]);
        end
      end;
    end;
    if (big[i].ss=0) then big[i].ss:=1;
    ans:=max(ans,big[i].ss);
    for j:=1 to lim do if nn[j]<>0 then maybe[j]:=nn[j];
    for j:=1 to lim do if maybe[j]<>0 then ans:=max(ans,j*2);
    if (ans=lim*2) then outp(i,lim,'');
  end;
  fillchar(maybe,sizeof(maybe),0);
  fillchar(num,sizeof(num),0);
  fillchar(big,sizeof(big),0);
  for i:=1 to n do
  begin
    fillchar(nn,sizeof(nn),0);
    for j:=lim downto 1 do
    begin
      if (maybe[j]<>0) and (maybe[j]>i) and (j*2+1>big[i].ss) then begin big[i].prev:=num[j]; big[i].ss:=j*2+1; end;
      if (j=1) then
      begin
        if (m[n,s[i]]<>i) then
        begin
          f[i,j].prev:=0; f[i,j].ss:=m[n,s[i]];
          if (m[n,s[i]]>maybe[j]) then num[j]:=i;
          nn[1]:=max(maybe[j],m[n,s[i]]);
        end;
      end
        else
      begin
        if (maybe[j-1]<>0) and (maybe[j-1]>i) and (m[maybe[j-1]-1,s[i]]>i) then
        begin
          f[i,j].prev:=num[j-1]; f[i,j].ss:=m[maybe[j-1]-1,s[i]];
          if (m[maybe[j-1]-1,s[i]]>maybe[j]) then num[j]:=i;
          nn[j]:=max(maybe[j],m[maybe[j-1]-1,s[i]]);
        end
      end;
    end;
    if (big[i].ss=0) then big[i].ss:=1;
    if (ans=big[i].ss) then outp(big[i].prev,big[i].ss div 2,s[i]);
    for j:=1 to lim do if nn[j]<>0 then maybe[j]:=nn[j];
    for j:=1 to lim do if (maybe[j]<>0) and (j*2=ans) then outp(i,j,'');
  end;
end.