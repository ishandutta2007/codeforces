Var
    a: array[1..1000] of longint;
     kol: array[97..122] of longint;
      answer: array[1..1000] of char;
       sv,tek,i,j,d,k,max: longint;
        s: ansistring;
         priz: boolean;
          sim:char;


procedure prost(ch:longint; var priz:boolean);
var i,pred:longint;
 begin
  priz:=false;
   pred:=round(sqrt(ch));
    for i:=2 to pred do
     if ch mod i = 0 then exit;
  priz:=true;
 end;


Begin

  readln(s);
   d:=length(s);
    sv:=0;
    for i:=2 to d do
     begin
      prost(i,priz);
       if priz=true
        then
         begin
          tek:=MaxLongint;
           for j:=1 to d do
            if (j mod i=0) and (a[j]<>0) and (tek>a[j]) then tek:=a[j];
          if tek = MaxLongint then begin inc(sv); tek:=sv; end;
           for j:=1 to d do
            if (j mod i=0) then a[j]:=tek;
         end;
     end;
  for i:=1 to d do
   if a[i]=0 then begin inc(sv); a[i]:=sv; end;

  for i:=1 to d do inc(kol[ord(s[i])]);

  for i:=1 to sv do
   begin
    k:=0;
     for j:=1 to d do if a[j]=i then inc(k);
    max:=0;
     for j:=97 to 122 do if kol[j]>max then
      begin
       max:=kol[j];
        sim:=chr(j);
      end;
    if max >= k
     then
      begin
       for j:=1 to d do
        if a[j]=i then answer[j]:=sim;
       dec(kol[ord(sim)],k);
      end
     else
      begin
       writeln('NO');
        halt;
      end;
   end;
  writeln('YES');
   for i:=1 to d do write(answer[i]);

End.