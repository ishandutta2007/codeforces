Program A2;
Var
  a : Array[1..1000] of String;
  b : Array[1..1000] of LongInt;
  na : Array[1..1000] of String;
  k : Array[1..1000] of LongInt;
  n,i,j,d1,ch,koef,kol,xod,kolo,code,chi : LongInt;
  s,namme,chiclo,nam : String;


Procedure proverka( ball:LongInt; Nam : String; var xod : LongInt );
Var i,kol:LongInt;
 Begin
  kol:=0;
  for i:=1 to n do
   if na[i]=nam then
                   begin
                    inc(kol,k[i]);
                    if kol>=ball then
                                     begin
                                      xod:=i;
                                      exit;
                                     end;
                   end;
 End;


BEGIN

  readln(n); kol:=0;
  for i:=1 to n do
   begin
    readln(s);
    j:=1; d1:=length(s);
    while s[j]<>' ' do inc(j);
    namme:=copy(s,1,j-1);
    chiclo:=copy(s,j+1,d1-j);
    val(chiclo,ch,code);

    na[i]:=namme;
    k[i]:=ch;

    koef:=0;
    for j:=1 to kol do
     if (a[j]=namme) then
                       begin
                        koef:=1;
                        inc(b[j],ch);
                        break;
                       end;
    if koef=0 then
                  begin
                   inc(kol);
                   a[kol]:=namme;
                   b[kol]:=ch;
                  end;

   end;

  kolo:=-1001; nam:=''; xod:=-1;

  for i:=1 to kol do
   begin
    if b[i]>kolo then
                     begin
                      kolo:=b[i];
                      nam:=a[i];
                      proverka(b[i],a[i],chi);
                      xod:=chi;
                     end;
    if (b[i]=kolo) then
                       begin
                        Proverka(b[i],a[i],chi);
                        if chi<xod then
                                       begin
                                        kolo:=b[i];
                                        nam:=a[i];
                                        xod:=chi;
                                      end;
                       end;
   end;

   writeln(nam);

END.