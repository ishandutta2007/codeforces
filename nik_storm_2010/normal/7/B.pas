Var
    a: array[1..101] of longint;
     t,n,tekblok,i,c,error: longint;
      s,sanswer,ss:string;


procedure alloc(nom:longint; var s:string);
var i,start,kol:longint;
     koef:boolean;
 begin
  start:=1; kol:=0; i:=1; koef:=false;
   while i<>n+1 do
    if a[i] = 0
     then
      begin
       inc(kol);
        if kol=nom then begin koef:=true; break; end;
       inc(i);
      end
     else
      begin
       while a[i]<>0 do inc(i); start:=i; kol:=0;
      end;
  if koef = false
   then s:='NULL'
   else
    begin
     inc(tekblok);
      for i:=1 to nom do a[start+i-1]:=tekblok;
     str(tekblok,s);;
    end;
 end;


procedure erase(nom:longint; var s:string);
var i:longint;
     priz:boolean;
 begin
  priz:=false;
   for i:=1 to n do
    if a[i] = nom then begin priz:=true; a[i]:=0; end;
   if (priz = false) or (nom=0) then begin s:='Didn`t Accept'; exit; end;
  s:='Accept';
 end;


procedure defragment;
var i,free:longint;
 begin
  free:=1;
   for i:=1 to n do
    if a[i]<>0
     then
      begin
       a[free]:=a[i]; if i<>free then a[i]:=0;
        inc(free);
      end;
 end;




Begin

  readln(t,n);
   for i:=1 to t do
    begin
     readln(s);

      if s[1] = 'a'
       then
        begin
         c:=length(s); ss:='';
          while s[c]<>' ' do begin ss:=s[c]+ss; dec(c); end;
           val(ss,c,error);
          alloc(c,sanswer);
         writeln(sanswer);
        end;

      if s[1] = 'e'
       then
        begin
         c:=length(s); ss:='';
          while s[c]<>' ' do begin ss:=s[c]+ss; dec(c); end;
           val(ss,c,error);
          erase(c,sanswer);
         if sanswer = 'Didn`t Accept' then writeln('ILLEGAL_ERASE_ARGUMENT');
        end;

      if s[1] = 'd'
       then
        begin
         defragment;
        end;

    end;

End.